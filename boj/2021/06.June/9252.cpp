#include <iostream>
#include <string>

using namespace std;

string s1, s2;
string answer[1001][1001];

int main(void)
{
    cin >> s1 >> s2;

    for(int r = 0 ; r < s2.size() ; r++)        // answer[r][c] 는 s2[0:r] 과 s1[0:c] 까지의 LCS
    {
        for(int c = 0 ; c < s1.size() ; c++)
        {
            if(s2[r] == s1[c]) answer[r+1][c+1] = answer[r][c] + s1[c];         // 같은 문자가 나올 경우 이번 문자가 추가되기 이전 문자열들의 LCS 에 이번 문자를 더해줌
            else answer[r+1][c+1] = (answer[r][c+1].size() > answer[r+1][c].size() ? answer[r][c+1] : answer[r+1][c]);  // 다른 문자라면 현재까지의 LCS 중 최대 길이의 LCS 를 선택
        }
    }

    cout << answer[s2.size()][s1.size()].size() << endl;
    if(answer[s2.size()][s1.size()].size())
        cout << answer[s2.size()][s1.size()] << endl;
}