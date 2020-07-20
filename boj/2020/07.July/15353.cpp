#include <iostream>

using namespace std;

string plused(string a, string b)                       // 두 문자열을 입력받아 더한 값을 문자열로 반환해주는 함수
{
    string temp = "";                   // 결과값 문자열
    int digitUp = 0;                    // 더할 때 자릿수 올림 처리
    while(a.size() != b.size())                         // 두 문자열의 자릿수를 똑같이 맞춰준다. (작은 값을 앞에 0을 붙여서)
    {
        if(a.size() < b.size())
        {
            a = '0' + a;
        }
        else
            b = '0' + b;
    }
    for(int i = a.size() - 1, k ; i >= 0 ; i--)         // 1의자리부터 시작해서 더해나간다
    {
        k = (a[i] - '0') + (b[i] - '0') + digitUp;      // 해당 자릿수 두개를 더함 (이전 자릿수에서의 올림처리도 같이해줌)
        if(k >= 10)
        {                                               // 10 이상일 경우 다음 자릿수 올림 처리
            digitUp = 1;
            k -= 10;
        }
        else
        {
            digitUp = 0;
        }
        temp = char(k + '0') + temp;                    // 결과 문자열에 해당 자릿수 더해줌
    }
    if(digitUp == 1) temp = '1' + temp;                 // 마지막 자릿수에서 올림이 있었다면 맨 앞에 또 올림처리
    return temp;
}

int main(void)
{
    string a, b;
    cin >> a >> b;
    cout << plused(a,b) << endl;
}