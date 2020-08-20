#include <iostream>
#include <vector>
#include <queue>

#define INF int(10e8)

using namespace std;

int V, E, K;
int u, v, w;

int main(void)
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> V >> E >> K;
    
    vector<int> answer(V+1, INF);                           // 각 인덱스는 각 노드까지의 최단거리를 담음
    vector<vector<pair<int,int>>> nodes(V+1);               // 전체 노드들 연결 정보를 담음
    
    for(int i = 0 ; i < E ; i++)                            // 간선들을 연결
    {
        cin >> u >> v >> w;                                 // 연결이 양방향으로 다 되는 것이 아니라, 주어진 방향으로만 연결됨을 주의
        nodes[u].push_back(pair<int,int>(v,w));
    }

    priority_queue<pair<int,int>> pq;                       // 우선순위 큐를 사용하여 다음에 탐색할 최단거리 노드가 앞에 올 수 있게
    pq.push(pair<int,int>(0,K));                            // 시작점은 K 번으로, 거리는 0으로 설정
    answer[K] = 0;

    while(pq.size())
    {
        int pos = pq.top().second;                          // 다음 탐색할 노드 정보
        int dist = -pq.top().first;
        pq.pop();           

        for(int i = 0 ; i < nodes[pos].size() ; i++)        // 해당 노드에서 연결된 다른 노드들 점검
        {
            int nextPos = nodes[pos][i].first;
            int nextDist = nodes[pos][i].second;
            if(dist + nextDist < answer[nextPos])           // 최단거리 갱신되는 노드들에만 대해서
            {
                answer[nextPos] = dist + nextDist;          // 업데이트 해주고
                pq.push(pair<int,int>(-(dist+nextDist), nextPos));  // 큐에 푸시
            }
        }
    }

    for(int i = 1 ; i <= V ; i++)                               // 최단거리들 최종적으로 출력
    {
        if(answer[i] == INF) cout << "INF" << '\n';
        else cout << answer[i] << '\n';
    }
}