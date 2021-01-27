#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int a, b, N, M, cnt;
int u, v;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b >> N >> M;
    if(a == b)                          // 혹시 같을 경우에 대한 예외처리
    {
        cout << 0 << endl;
        return 0;
    }

    vector<int> graph[N + 1];           // 엣지 리스트
    vector<bool> visited(N + 1, false); // 중복 방문 피하기 위한 배열

    for(int i = 0 ; i < M ; i++)
    {
        cin >> u >> v;
        graph[u].push_back(v);          // 양방향으로 연결
        graph[v].push_back(u);
    }

    queue<int> q;
    q.push(a);                          // 주어진 a 부터 시작해서
    visited[a] = true;

    while(q.size())
    {
        int sz = q.size();
        for(int k = 0 ; k < sz ; k++)   // 같은 너비에 있는 친구는 한번에 다같이 처리
        {
            int cur = q.front();
            q.pop();
            if(cur == b)
            {
                cout << cnt << endl;
                return 0;
            }
            for(int i = 0 ; i < graph[cur].size() ; i++)    // 자신에게 연결된 노드들 중
            {
                int next = graph[cur][i];
                if(!visited[next])                          // 방문하지 않은 노드에 대해서 푸시해주고
                {
                    q.push(next);
                    visited[next] = true;                   // 방문처리를 미리 해줌
                }
            }
        }
        cnt++;
    }

    cout << -1 << endl;
}