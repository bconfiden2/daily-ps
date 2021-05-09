#include <iostream>
#include <string>

using namespace std;

string A, B;
string answer = "";

int main(void)
{
    cin >> A >> B;

    for(int i = 0 ; i < abs(int(B.length()-A.length())) ; i++) answer += "0";
    if(A.length() < B.length()) A = answer + A;     // 더 큰 값의 자릿수에 맞게 문자열을 0 으로 채워준다
    else                        B = answer + B;
    answer = "";

    bool flag = false;                              // 자릿수 올림에 관한 플래그
    for(int i = B.length() - 1 ; i >= 0 ; i--)
    {
        int temp = (B[i]-'0') + (A[i]-'0');         // 현재 자릿수를 더해주고
        if(flag) temp++;                            // 이전 자릿수에서 올림값이 있으면 더해주교ㅗ
        flag = temp / 10;                           // 이번 자리의 올림값 여부 확인
        answer = to_string(temp % 10) + answer;     // 현재 자리 값 결정
    }
    if(flag) answer = "1" + answer;                 // 마지막 자리에서 올림 있었는지 확인
    cout << answer << endl;
}