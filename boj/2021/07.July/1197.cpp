#include <iostream>
#include <queue>

using namespace std;

int V, E, A, B, C;
int answer, cnt;
int parents[10001];

int find_(int cur)                              // 루트노드를 찾아주는 find 함수
{
    if(parents[cur] == 0) return cur;
    parents[cur] = find_(parents[cur]);
    return parents[cur];
}

int main(void)
{
    priority_queue<pair<int, pair<int,int>>> pq;

    cin >> V >> E;
    for(int i = 0 ; i < E ; i++)
    {
        cin >> A >> B >> C;
        pq.push({-C, {A,B}});                   // 가중치를 음수로 넣어서 pq 오름차순 구현
    }

    while(pq.size())
    {
        int cur = -pq.top().first;              // 현재 간선의 가중치
        int c1 = find_(pq.top().second.first);  // 두 노드의 루트 노드를 찾음
        int c2 = find_(pq.top().second.second);
        pq.pop();

        if(c1 == c2) continue;                  // 루트가 같을 경우, 순환 형성하므로 스킵
        answer += cur;
        parents[c1] = c2;                       // 유니온 시켜주고
        if(++cnt == V-1) break;                 // V-1 개 간선이 연결됐으면 MST 완성
    }
    cout << answer << endl;
}