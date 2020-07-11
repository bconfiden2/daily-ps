#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Point
{
    int x;
    int y;    
};

int ABS(int n)                              // 절댓값 반환해주는 함수
{
    return n < 0 ? -n : n;
}

int tc, n;

int main(void)
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> tc;
    for(int t = 0 ; t < tc ; t++)
    {
        cin >> n;
        vector<Point> pos(n + 2);                       // 시작점, 편의점들, 끝점 위치 정보
        vector<vector<int>> linked(n + 2);              // 편의점 간 연결 정보
        vector<bool> temp(n+2);                         // 임시
        vector<vector<bool>> linkcheck(n + 2, temp);    // 노드 간 이미 연결이 되어있었는지 확인하는 정보
        for(int i = 0 ; i < n + 2 ; i++)
        {                                               // pos[0] 시작점
            cin >> pos[i].x >> pos[i].y;                // pow[1] ~ pos[n] 편의점
        }                                               // pos[n + 1] 끝점

        for(int i = 0 ; i < n + 2 ; i++)
        {
            for(int j = 0 ; j < n + 2 ; j++)
            {
                if(i == j) continue;
                if(ABS(pos[i].x - pos[j].x) + ABS(pos[i].y - pos[j].y) <= 1000) // 편의점 간 거리가 1000 이하면 연결
                {
                    if(linkcheck[i][j] || linkcheck[j][i]) continue;    // 이미 연결이 되어있었다면 넘어감
                    linked[i].push_back(j);
                    linked[j].push_back(i);                             // 서로 연결을 시켜주고
                    linkcheck[i][j] = true;
                    linkcheck[j][i] = true;                             // 연결되었다고 표시도 해줌
                }
            }
        }
        queue<int> q;   
        q.push(0);                                              // 집에서 출발
        bool able = false;
        vector<bool> visited(n + 2, false);                     // 편의점 방문 여부
        while(!q.empty())                                       // 가능한 곳이 없을 때 까지
        {
            int cur = q.front();
            if(cur == n + 1)                                    // 만약 도착점에 도달했으면 종료
            {
                able = true;
                break;
            }                                                   // 도착점이 아닐 경우,
            visited[cur] = true;                                // 편의점 방문했음을 체크해주고
            for(int i = 0 ; i < linked[cur].size() ; i++)       // 해당 편의점에 연결되어있는 노드들 푸시
            {
                if(visited[linked[cur][i]] == false)            //   (방문 안했던 노드만 푸시)
                    q.push(linked[cur][i]);
            }
            q.pop();
        }
        if(able) cout << "happy" << '\n';
        else cout << "sad" << '\n';
    }
}