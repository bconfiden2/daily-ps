#include <iostream>
#include <string>
using namespace std;

string n;                       // 원하는 채널값을 string 으로 받음 (길이 재기 위해서)
int intN, m, ans = 500000;      // intN 이 n 을 정수로 바꾼 실제 값
bool buttons[10];               // 고장여부 정보

int abs(int a) { return a >= 0 ? a : -a; }  // 절댓값 반환

int check(int num)              // 완전탐색 함수
{
    int temp = num;             // 임시 변수 temp 는 해당 숫자가 고장 안 난 숫자들로 이루어졌는지 확인위해
    int digit = 0;              // 자릿수 저장
    while(true)
    {
        if(buttons[temp % 10]) return 1000000;      // 자리 하나씩 검사하면서 고장난 번호가 있으면 이상값 반환
        digit++;                                    // 해당 자리에 문제가 없으면 자릿수 1 증가시켜주고
        temp /= 10;                                 // 한자리 지움
        if(temp == 0) break;                        // 더 자리가 없으면 종료
    }
    return digit + abs(intN - num);                 // 해당 채널로 번호 누른 횟수 + 채널에서 목표값까지의 횟수 반환
}

int main(void)
{
    cin >> n >> m;
    for(int i = 0, data ; i < m ;i++)
    {
        cin >> data;
        buttons[data] = true;
    }
    for(int i = n.size() - 1, temp = 1 ; i >= 0 ; i--, temp *= 10)
    {
        intN += temp * (n[i] - '0');
    }
    int pure = abs(intN - 100);                                         // 100 부터 +- 로만 돌렸을 때의 횟수
    if(m == 0) cout << (pure > n.size() ? n.size() : pure) << '\n';     // 고장난게 없을 때 먼저 처리해주고
    else if(m == 10) cout << pure << '\n';                              // 모두 고장났을 때도 처리해준 다음
    else
    {
        for(int i = 0, temp ; i <= 1000000 ; i++)                       // 1 ~ 1000000 까지 모든 채널 완전탐색
        {
            temp = check(i);                                            // 해당 채널의 클릭횟수를 받아서
            if(temp < ans) ans = temp;                                  // 최솟값인지 확인
        }
        if(pure >= ans)  cout << ans << '\n';
        else cout << pure << '\n';
    }
}