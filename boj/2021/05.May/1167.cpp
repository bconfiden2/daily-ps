#include <iostream>
#include <vector>

using namespace std;

int V, v, u, w;
int node, answer;
vector<vector<pair<int,int>>> tree;
vector<bool> visited;

void dfs(int s, int dist)
{
    if(dist > answer)                           // dfs 안에서 최대거리와 해당 노드 갱신
    {
        answer = dist;
        node = s;
    }
    for(int i = 0 ; i < tree[s].size() ; i++)  // 재귀 호출
    {
        pair<int, int> cur = tree[s][i];
        if(visited[cur.first]) continue;        // 방문했던 노드는 재방문하지 않음
        visited[cur.first] = true;
        dfs(cur.first, dist + cur.second);
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> V;
    for(int i = 0 ; i <= V ; i++)
    {
        vector<pair<int,int>> node;
        tree.push_back(node);
        visited.push_back(false);
    }
    for(int i = 1 ; i <= V ; i++)
    {
        cin >> v >> u;
        while(u != -1)
        {
            cin >> w;
            tree[v].push_back({u, w});
            cin >> u;
        }
    }

    visited[1] = true;                          // 임의의 점에서 출발하여 최대거리인 노드 확인
    dfs(1, 0);
    for(int i = 1 ; i <= V ; i++) visited[i] = false;
    visited[node] = true;                       // 해당 노드부터 다시 최대거리를 확인하면 트리의 지름이 됨
    dfs(node, 0);
    cout << answer << endl;
}