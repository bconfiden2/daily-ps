#include <iostream>

using namespace std;

int n;
unsigned long long answer;
unsigned long long data[2][10];                     // 10개의 열은, 0~9 까지 각각 몇개의 숫자가 가능한지 담아놓음

int main(void)
{
    cin >> n;
    for(int i = 1 ; i <= 9 ; i++)                   // 0 으로 시작할 수 없기 때문에 1~9 까지만 가능한 숫자
    {
        data[1][i] = 1;
    }
    for(int digit = 2 ; digit <= n ; digit++)       // n 의 자리까지 
    {
        data[digit%2][0] = data[(digit+1)%2][1];    // 0 는 직전 자릿수의 +1 위치 (1) 의 값만을 더함
        data[digit%2][9] = data[(digit+1)%2][8];    // 9 는 직전 자릿수의 -1 위치 (8) 의 값만을 더함
        for(int i = 1 ; i <= 8 ; i++)               // 1~8 까지는 직전 자릿수의 (-1/+1) 위치의 값들을 더함
        {
            data[digit%2][i] = (data[(digit+1)%2][i-1] + data[(digit+1)%2][i+1]) % 1000000000;
        }
    }
    for(int i = 0 ; i <= 9 ; i++)
    {
        answer = (answer + data[n%2][i]) % 1000000000;  // 해당 자릿수에서 가능한 숫자의 갯수들을 모두 더함
    }
    cout << answer << endl;
}