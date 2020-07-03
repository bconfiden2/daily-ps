#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void)
{
    string s;
    cin >> s;
    vector<int> plus;    // 더하기 될 숫자들의 모음
    vector<int> minus;   // 빼기 될 숫자들의 모음
    int temp = 0, target = s.size();    // target 은 처음으로 마이너스가 나오는 자리
    for(int i = 0 ; i < s.size() ; i++)
    {
        if(s[i] == '-')
        {
            target = i;                 // target 위치를 구해놓고
            break;
        }
    }
    for(int i = 0 ; i < target ; i++)   // 처음으로 - 가 나오기 전까지는 다 plus 에 넣어준다
    {                                   // 플러스와 마이너스 사이에 인덱스 조절 신경써줘야 한다
        if(s[i] == '+' || s[i] == '-')
        {
            plus.push_back(temp);
            temp = 0;
        }
        else
        {
            temp = temp * 10 + int(s[i] - '0');
        }
    }
    plus.push_back(temp);
    temp = 0;
    for(int i = target + 1 ; i < s.size() ; i++)        // 그 이후의 숫자들부터는 minus 에 넣음
    {
        if(s[i] == '+' || s[i] == '-')
        {
            minus.push_back(temp);
            temp = 0;
        }
        else
        {
            temp = temp * 10 + int(s[i] - '0');
        }
    }
    if(target != s.size()) minus.push_back(temp);       // 만약 - 가 하나도 나오지 않았을 경우는 플러스들만 더해줌
    int ans = 0;
    for(int i = 0 ; i < plus.size() ; i++) 
    {
        ans += plus[i];                                 // 플러스 친구들은 더해주고
    }
    for(int i = 0 ; i < minus.size() ; i++)             // 마이너스 친구들은 빼주면 답이 나옴!
    {
        ans -= minus[i];
    }
    cout << ans << '\n';
}