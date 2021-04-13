#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int tc;
int v, e, a, b;

void cased()
{
    cin >> v >> e;
    vector<int> graph[v+1];
    vector<int> visited(v+1, -1);                               // 노드의 그룹과 방문 여부에 대한 배열. -1 이 미방문
    for(int i = 0 ; i < e ; i++)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int start = 1 ; start <= v ; start++)                   // 여러 개의 bipartite 그래프가 존재할 수 있기 때문에
    {                                                           // 가능한 여러 그래프들에 대해서 모두 검사함
        if(visited[start] != -1) continue;

        queue<pair<int, int>> q;                                // 방문하지 않은 점부터 시작하여 하나의 bipartite 그래프에 대해서 검사
        q.push({start, 0});

        while(q.size())
        {
            int sz = q.size();                                  // bfs 를 한번 돌 때 마다, 왼쪽과 오른쪽을 왔다갔다 한다고 보면 됨
            for(int ix = 0 ; ix < sz ; ix++)                    // 현재 큐에 들어있는 모든 노드들에 대해서
            {
                int cur = q.front().first;
                int group = q.front().second;
                q.pop();

                visited[cur] = group;                           // 현재 노드가 왼쪽 그룹인지 오른쪽 그룹인지 표시해주고
                for(int i = 0 ; i < graph[cur].size() ; i++)    // 자기가 가리키고 있는 노드들 확인
                {
                    int next = graph[cur][i];
                    if(visited[next] == group)                  // 만약 내가 가리키고 있는 노드들 중 나와 같은 그룹이 있다면
                    {                                           // 해당 노드는 왼쪽 그룹과 오른쪽 그룹에 모두 포함되어있다는 뜻이기 떄문에
                        cout << "NO" << endl;                   // 이분그래프 불가능
                        return;
                    }
                    if(visited[next] == -1) q.push({next, (group + 1) % 2});
                }
            }
        }
    }

    cout << "YES" << endl;                                      // 전체 그래프 안의 모든 그래프들이 이분그래프라면, 두 개로 나눌 수 있음
}

int main(void)
{
    cin >> tc;
    while(tc--) cased();
}