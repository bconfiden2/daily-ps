#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;

int main(void)
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n;

    vector<vector<int>> nodes(n + 1);                   // 노드 연결 정보
    vector<bool> visited(n + 1, false);                 // 노드 방문여부 체크할 벡터
    vector<int> answer(n + 1, 0);                       // 해당 노드의 부모 노드 저장할 벡터
    for(int i = 0, a, b ; i < n-1 ; i++)
    {
        cin >> a >> b;
        nodes[a].push_back(b);                          // 노드 서로 연결시켜줌
        nodes[b].push_back(a);
    }

    queue<int> q;                                       // BFS 탐색용 큐
    q.push(1);                                          // 루트인 1부터 시작
    visited[1] = true;
    while(q.size())
    {
        int cur = q.front();
        for(int i = 0 ; i < nodes[cur].size() ; i++)    // 자신에게 연결된 노드들을 큐에 담음
        {
            int temp = nodes[cur][i];
            if(visited[temp]) continue;                 // 이미 방문했던 노드는 제외
            q.push(temp);
            visited[temp] = true;                       // 해당 노드들의 부모값을 넣어줌
            answer[temp] = cur;
        }
        q.pop();
    }

    for(int i = 2 ; i <= n ; i++)
    {
        cout << answer[i] << '\n';
    }
}