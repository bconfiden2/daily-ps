#include <iostream>
#include <vector>
#include <queue>

#define INF 10e8

using namespace std;

int n, e, answer;
int a, b, c;
int v1, v2;
vector<pair<int,int>> nodes[801];

int dijkstra(int start, int end)                            // 시작점과 끝점이 주어졌을 때 다익스트라로 최단거리 반환
{
    int ret = -1;
    vector<int> visited(n+1, INF);                          // visited 배열은 각 인덱스(노드)의 최단거리 저장, INF 로 초기화

    priority_queue<pair<int,int>> pq;
    pq.push(pair<int,int>(0, start));                       // start 부터 시작
    visited[start] = 0;

    while(pq.size())
    {
        int pos = pq.top().second;                          // 이번 노드를 꺼내서 확인
        int dist = -pq.top().first;
        pq.pop();

        for(int i = 0 ; i < nodes[pos].size() ; i++)        // 노드에 연결되어있는 다른 노드들 모두 확인하는데
        {
            int nextPos = nodes[pos][i].second;
            int nextDist = nodes[pos][i].first;
            
            if(dist + nextDist < visited[nextPos])          // 최단거리 갱신이 가능한 노드들만 집어넣음
            {
                visited[nextPos] = dist + nextDist;         // 업데이트 해주고 큐에 푸시함
                pq.push(pair<int,int>(-(dist + nextDist), nextPos));
            }
        }
    }

    return (visited[end] == INF ? -1 : visited[end]);
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> e;
    for(int i = 0 ; i < e ; i++)
    {
        cin >> a >> b >> c;
        nodes[a].push_back(pair<int,int>(c, b));                        // 간선 연결 (양방향)
        nodes[b].push_back(pair<int,int>(c, a));
    }
    cin >> v1 >> v2;

    int a1 = dijkstra(1, v1) + dijkstra(v1, v2) + dijkstra(v2, n);      // 1 ~ v1 ~ v2 ~ n 까지의 최단거리
    int a2 = dijkstra(1, v2) + dijkstra(v2, v1) + dijkstra(v1, n);      // 1 ~ v2 ~ v1 ~ n 까지의 최단거리
    answer = min(a1, a2);
    if (answer == - 3) answer = -1;                                     // 둘 중 작은 값을 택한다

    cout << answer << endl;
}