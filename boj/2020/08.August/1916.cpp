#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int s, e, c;
int b, f;
int answer[1001];
vector<vector<pair<int,int>>> nodes(1001);

int main(void)
{
    cin >> n >> m;
    for(int i = 0 ; i < m ; i++)
    {
        cin >> s >> e >> c;
        nodes[s].push_back(pair<int,int>(c, e));            // 도시 간 연결 정보
    }
    cin >> b >> f;

    for(int i = 1 ; i <= n ; i++)                           // 초기값 설정은 불가능을 나타내는 이상치로 설정
    {
        answer[i] = 10e8;
    }

    priority_queue<pair<int,int>> pq;
    pq.push(pair<int,int>(0, b));                           // 우선순위 큐 선언해주고 시작점부터 계산시작
    answer[b] = 0;

    while(pq.size())
    {
        int pos = pq.top().second;                          // 이번에 검사할 도시와
        int dist = -pq.top().first;                         // 해당 도시까지의 최단거리값 저장해놓음
        pq.pop();

        if(pos == f) break;                                 // 도착점 도달 시 그냥 종료

        for(int i = 0 ; i < nodes[pos].size() ; i++)        // 해당 도시에 연결된 다른 도시들 검사
        {
            int nextPos = nodes[pos][i].second;
            int nextDist = nodes[pos][i].first;
            if(dist + nextDist < answer[nextPos])           // 다른 도시들 중 최단거리 갱신할 수 있는 도시가 있다면
            {
                answer[nextPos] = dist + nextDist;          // 업데이트 해주고
                pq.push(pair<int,int>(-(dist+nextDist), nextPos));  // 큐에 넣어줌 (거리에 - 를 붙여 최단거리 확인)
            }
        }
    }

    cout << answer[f] << endl;
}