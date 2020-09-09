#include <iostream>

using namespace std;

int n;
int num[1000001] = {0, 1, 2, 3, 5};

int main(void)
{
    cin >> n;
    for(int i = 5 ; i <= n ; i++)
    {
        num[i] = ((num[i-1] % 15746) + (num[i-2] % 15746)) % 16746;
        // i-2 자리에 00 이 붙을 수 있고, i-1 자리에 1 이 붙을 수 있기 때문에 피보나치 수열과 같음
        // 모듈러 연산의 특성에 의하여 나머지 연산을 매번 해줌
    }
    cout << num[n] << endl;
}

/**********************************************
#include <stdio.h>
int N, a[3];
int main(int argc, char* argv[])
{
    scanf("%d", &N);

    a[0] = 1;
    a[1] = 1;
    for(int i = 2 ; i <= N ; i++)
    {
        a[2] = a[0] + a[1];
        if(a[2] >= 15746) a[2] -= 15746;
        a[0] = a[1];
        a[1] = a[2];
    }
    printf("%d", a[1]);
}
**********************************************/