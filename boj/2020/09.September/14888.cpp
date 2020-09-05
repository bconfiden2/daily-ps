#include <iostream>

using namespace std;

int n;
int maxi = -10e8, mini = 10e8;
int numbers[11];
int remain_ops[4];

void check(int size, int value)                         // size = 이번에 정할 자릿수, value = 지금까지 고른 연산자들로 구한 값
{
    if(size == n)                                       // 모든 자릿수를 다 정했을 때
    {
        if(value < mini) mini = value;                  // 최댓값과 최솟값 갱신해주고 종료
        if(value > maxi) maxi = value;
        return;
    }
    for(int i = 0 ; i < 4 ; i++)                        // +-*/ 4개에 대해서 사용할게 있는지 검사
    {
        if(remain_ops[i] > 0)                           // 사용가능하다면
        {
            remain_ops[i]--;                            // 연산자 하나 사용
            int nextValue = value;

            if(i == 0)      nextValue += numbers[size]; // 각 연산자에 맞게 값에 추가 연산
            else if(i == 1) nextValue -= numbers[size];
            else if(i == 2) nextValue *= numbers[size];
            else            nextValue /= numbers[size];

            check(size + 1, nextValue);                 // 이번 연산에 구한 값을 넘겨주면서 다음 자릿수를 구함
            remain_ops[i]++;                            // 이번 반복에 썼던 연산자 되돌림
        }
    }
}

int main(void)
{
    cin >> n;
    for(int i = 0 ; i < n ; i++)            // 수 입력
        cin >> numbers[i];

    for(int i = 0 ; i < 4 ; i++)            // 연산자 갯수들 입력
        cin >> remain_ops[i];

    check(1, numbers[0]);                   // 맨 처음 값은 첫번째 숫자값으로 주고 2번째 자리부터 백트래킹 시작

    cout << maxi << '\n' << mini << '\n';
}

/*******************************************************
#include <cstdio>

int n, a[13];
int maxi = -10e8;
int mini = 10e8;
int x, y, z, w;

void f(int s, int g)
{
    if(s == n)
    {
        if(g > maxi) maxi = g;
        if(g < mini) mini = g;
    }
    if(x) { x-- ; f(s + 1, g + a[s+1]) ; x++; }
    if(y) { y-- ; f(s + 1, g - a[s+1]) ; y++; }
	if(z) { z-- ; f(s + 1, g * a[s+1]) ; z++; }
	if(w) { w-- ; f(s + 1, g / a[s+1]) ; w++; }
}

int main()
{
    scanf("%d", &n);
    for(int i = 1 ; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    scanf("%d %d %d %d", &x, &y, &z, &w);
    f(1, a[1]);
    printf("%d %d", maxi, mini);
}
****************************************************/