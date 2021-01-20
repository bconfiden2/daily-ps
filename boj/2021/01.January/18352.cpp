#include <iostream>
#include <queue>
#include <vector>

#define INF 10000000

using namespace std;

int N, M, K, X;
int u, k;

int main(void)
{
    cin >> N >> M >> K >> X;
    vector<vector<int> > v(N+1, vector<int>(0,0));      // 연결 정보를 담은 2차원 벡터
    vector<int> distance(N+1, INF);                     // 최단 거리 정보
    
    for(int i = 0 ; i < M ; i++)
    {        
        cin >> u >> k;
        v[u].push_back(k);                              // 단방향으로 연결
    }

    priority_queue<pair<int,int>> q;
    q.push({0, X});                                     // 시작점부터 출발
    distance[X] = 0;
    while(q.size())
    {
        int dist = -q.top().first;                      // 거리를 음수화해서 우선순위 큐에 집어넣기 때문에
        int city = q.top().second;                      // 꺼낼 때도 양수로 바꿔서 가져온다
        q.pop();
        if(distance[city] < dist) continue;             // 만약 최단거리가 아니었던 점이라면 스킵
        for(int i = 0 ; i < v[city].size() ; i++)       // 해당 도시에서 연결된 모든 도시들에 대해서
        {
            int nextDist = dist + 1;
            if(nextDist < distance[v[city][i]])         // 이번 방문으로 최단거리가 갱신된다면
            {
                distance[v[city][i]] = nextDist;        // 업데이트 해주고
                q.push({-nextDist, v[city][i]});        // 큐에 새롭게 또 넣어준다.
            }
        }
    }

    bool none = true;
    for(int i = 1 ; i <= N ; i++)
    {
        if(distance[i] == K)
        {
            cout << i << endl;
            none = false;
        }
    }
    if(none) cout << -1 << endl;
}