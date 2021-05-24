#include <iostream>
#include <vector>
#include <queue>

#define INF 1000000000

using namespace std;

struct Node
{
    int cost;
    int city;
    string path;
};

int n, m, a, b, w, start_, end_;
vector<pair<int,int>> graph[1001];                      // 그래프 연결 정보 저장
vector<pair<int,string>> dist(1001, {INF, ""});         // 최단거리 및 경로를 저장

struct cmp
{
    bool operator()(Node& a, Node& b)                   // 우선순위큐에서 비교를 위해 사용되는 구조체
    {
        return a.cost < b.cost;
    }
};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i = 0 ; i < m ; i++)
    {
        cin >> a >> b >> w;
        graph[a].push_back({b, w});
    }

    cin >> start_ >> end_;

    priority_queue<Node, vector<Node>, cmp> pq;
    pq.push({0, start_, to_string(start_)});
    dist[start_].first = 0;
    while(pq.size())
    {
        int curDist = -pq.top().cost;
        int curCity = pq.top().city;
        string curPath = pq.top().path;
        pq.pop();
        if(dist[curCity].first < curDist) continue;             // 만약 최소 거리가 그 사이에 갱신되었다면 스킵

        if(curCity == end_)                                     // 목표 지점에 도달하면
        {
            cout << curDist << endl;                            // 최소 비용 출력 후
            int cnt = 1;
            for(int i = 0 ; i < curPath.size() ; i++)           // 경로에 껴있는 도시들의 개수 센 뒤 출력
            {
                if(curPath[i] == ' ') cnt++;
            }
            cout << cnt << endl;
            cout << curPath << endl;                            // 경로도 출력
        }
                                                                // 목표 지점이 아니라면
        for(int i = 0 ; i < graph[curCity].size() ; i++)        // 현재 위치에서 연결된 모든 노드들 확인
        {
            int nextCity = graph[curCity][i].first;
            int nextDist = graph[curCity][i].second + curDist;
            if(nextDist < dist[nextCity].first)                 // 최소 거리로 갱신되는 노드가 있다면
            {
                dist[nextCity].first = nextDist;                // 해당 노드 업데이트 후 pq 에 넣어줌
                dist[nextCity].second = curPath + " " + to_string(nextCity);
                pq.push({-nextDist, nextCity, dist[nextCity].second});
            }
        }
    }
}