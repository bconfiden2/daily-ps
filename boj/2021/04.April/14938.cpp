#include <iostream>
#include <vector>
#include <queue>

#define INF 1000000000

using namespace std;

int n, m, r;
int a, b, l;
int items[100];
vector<pair<int, int>> graph[100];

int dijkstra(int start)                 // 특정 시작점에서 얻을 수 있는 아이템의 개수 반환
{
    vector<int> length(n, INF);
    priority_queue<pair<int, int>> pq;

    length[start] = 0;
    pq.push({0, start});                // 시작점에서 다익스트라 출발

    while(pq.size())
    {
        int curDist = -pq.top().first;
        int curNode = pq.top().second;
        pq.pop();

        if(length[curNode] < curDist) continue;                 // 이미 최소거리로 갱신된 노드라면 스킵

        for(int i = 0 ; i < graph[curNode].size() ; i++)        // 연결된 노드들에 대해서
        {
            int nextDist = curDist + graph[curNode][i].second;
            int nextNode = graph[curNode][i].first;
            if(nextDist < length[nextNode])                     // 거리 갱신되는 노드가 있으면
            {
                length[nextNode] = nextDist;                    // 업데이트 한 뒤
                pq.push({-nextDist, nextNode});                 // 큐에 넣어줌
            }
        }
    }

    int ret = 0;
    for(int i = 0 ; i < n ; i++)            // 모든 위치에 대해서
    {
        if(length[i] <= m) ret += items[i]; // 얻을 수 있는 아이템인지 확인 후 처리
    }
    return ret;
}

int main(void)
{
    cin >> n >> m >> r;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> items[i];
    }
    for(int i = 0 ; i < r ; i++)
    {
        cin >> a >> b >> l;
        graph[a-1].push_back({b-1, l});
        graph[b-1].push_back({a-1, l});
    }
    int answer = 0;
    for(int i = 0 ; i < n ; i++)            // 모든 시작점에 대해서 검사하며
    {
        int temp = dijkstra(i);             // 가장 많이 아이템을 얻는 위치 검사
        if(temp > answer) answer = temp;
    }
    cout << answer << endl;
}