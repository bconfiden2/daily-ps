#include <iostream>
#include <vector>
#include <queue>

#define ull unsigned long long
#define INF 10000000000000

using namespace std;

int N, M, a, b, t;

int main(void)
{
    cin >> N >> M;
    vector<bool> forbidden(N, false);
    vector<vector<pair<int,int>>> graph;
    for(int i = 0 ; i < N ; i++)
    {
        cin >> t;
        forbidden[i] = (t == 1 ? true : false);
        vector<pair<int,int>> v;
        graph.push_back(v);
    }
    for(int i = 0 ; i < M ; i++)
    {
        cin >> a >> b >> t;
        if(forbidden[a] || forbidden[b])            // 만약 적에게 노출되는 지점이라면 애초에 연결을 시켜주지 않음
        {
            if(a != N-1 && b != N-1) continue;      // 다만 마지막 지점은 연결시켜줘야함
        }
        graph[a].push_back({b, t});                 // 양방향 연결
        graph[b].push_back({a, t});
    }

    vector<ull> dist(N, INF);
    priority_queue<pair<ull, int>> pq;
    pq.push({0,0});
    dist[0] = 0;

    while(pq.size())                                // 기본적인 다익스트라 구조
    {
        ull curDist = -pq.top().first;              // 최대거리가 100억까지 가능하기 때문에 int 로는 표현 불가능하다
        int curNode = pq.top().second;
        pq.pop();
        if(dist[curNode] < curDist) continue;
        for(int i = 0 ; i < graph[curNode].size() ; i++)
        {
            ull nxtDist = curDist + graph[curNode][i].second;
            int nxtNode = graph[curNode][i].first;
            if(nxtDist < dist[nxtNode])
            {
                dist[nxtNode] = nxtDist;
                pq.push({-nxtDist, nxtNode});
            }
        }
    }
    if(dist[N-1] == INF) cout << -1 << endl;
    else cout << dist[N-1] << endl;
}