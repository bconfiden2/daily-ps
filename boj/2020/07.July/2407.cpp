#include <iostream>

using namespace std;

int n, m;
string answers[101][101];                               // 메모이제이션

string plused(string a, string b)                       // 두 수의 합을 더해주는 함수 (15353번 소스코드)
{
    string temp = "";
    int digitUp = 0;
    while(a.size() != b.size())
    {
        if(a.size() < b.size())
        {
            a = '0' + a;
        }
        else
            b = '0' + b;
    }
    for(int i = a.size() - 1, k ; i >= 0 ; i--)
    {
        k = (a[i] - '0') + (b[i] - '0') + digitUp;
        if(k >= 10)
        {
            digitUp = 1;
            k -= 10;
        }
        else
        {
            digitUp = 0;
        }
        temp = char(k + '0') + temp;
    }
    if(digitUp == 1) temp = '1' + temp;
    return temp;
}

string check(int r, int k)                                                  // 재귀적으로 해당 조합의 값을 구하는 함수
{
    if(answers[r][k] != "") return answers[r][k];                           // 이미 구해놨던 값이 있으면 해당 값을 반환
    if(k == 0 || r == k)                                                    // 재귀 탈출 부분, nCr 에서 r 이 0 이거나 n과 r 이 같을 경우
    {
        answers[r][k] = "1";
        return "1";
    }
    else
    {
        answers[r][k] = plused(check(r - 1, k - 1), check(r - 1, k));       // 그게 아니라면, (n-1 C r-1) + (n-1 C r) 을 구해줌
        return answers[r][k];
    }
}

int main(void)
{
    cin >> n >> m;
    check(n, m);
    cout << answers[n][m] << '\n';
}