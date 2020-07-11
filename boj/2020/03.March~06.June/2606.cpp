#include <iostream>
#include <vector>
using namespace std;

// dfs 함수
void dfs(vector<vector<int>>& v, vector<bool>& checked, int idx)
{
    // 체크되었는지 검사
    if(checked[idx]) return;
    checked[idx] = true;
    // 재귀호출
    for(int i = 0 ; i < v[idx].size() ; i++)
    {
        dfs(v, checked, v[idx][i]);
    }
}

int main(void)
{
    int n, line;
    int answer = 0;
    cin >> n;
    cin >> line;

    // 컴퓨터 연결 정보
    vector<vector<int>> v(n);
    // 체크 정보
    vector<bool> checked(n, false);

    int lf, rf;
    // 노드들 양방향 연결
    for(int i = 0 ; i < line ; i++)
    {
        cin >> lf >> rf;
        v[lf - 1].push_back(rf - 1);
        v[rf - 1].push_back(lf - 1);
    }
    // 1번 컴퓨터에 연결된 친구들만 확인
    dfs(v, checked, 0);
    
    // 1번 컴퓨터는 제외니까 빼준다
    for(int i = 1 ; i < n ; i++)
    {
        if(checked[i]) answer++;
    }
    cout << answer << '\n';
}