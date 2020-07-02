#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

void dfs(int start, vector<vector<int>>& graphs)        // DFS 
{
    vector<int> visited(graphs.size(), false);          // 방문 여부 체크용
    stack<int> df;
    df.push(start);
    while(!df.empty())                                  // 스택이 비워질때까지 반복
    {
        int cur = df.top();                             // 스택 맨 위에 있는 값 (현재 반복에서의 타겟)
        if(visited[cur])                                // 만약 방문한 노드라면
        {
            df.pop();                                   // 그냥 무시
            continue;
        }
        visited[cur] = true;                            // 그렇지 않다면 방문했다고 체크해주고
        cout << cur << " ";                             // 출력한 뒤
        df.pop();                                       // 빼 준다
        vector<int> childs;                             // (문제에서 정점 번호가 작은것 먼저 방문하라해서)
        for(int i = 0 ; i < graphs[cur].size() ; i++)
        {
            int temp = graphs[cur][i];
            if(visited[temp] == false)
            {
                childs.push_back(temp);                  // 들어갈 자식 노드들을 확인해서
            }
        }
        sort(childs.begin(), childs.end(), greater<int>()); // 작은 번호 먼저 들어가게끔 내림차순 정렬
        for(int i = 0 ; i < childs.size() ; i++)
        {
            df.push(childs[i]);                             // 큰 번호를 먼저 푸시해줌
        }
    }
    cout << '\n';
    return;
}
void bfs(int start, vector<vector<int>>& graphs)        // BFS
{   
    for(int i = 1 ; i < graphs.size() ; i++)
    {                                                   // 얘는 큐이기 때문에 오름차순 정렬을 해줌
        sort(graphs[i].begin(), graphs[i].end());
    }
    vector<int> visited(graphs.size(), false);          // 나머지는 DFS 와 거의 유사
    queue<int> bf;
    bf.push(start);
    while(!bf.empty())
    {
        int cur = bf.front();
        if(visited[cur])
        {
            bf.pop();
            continue;
        }
        visited[cur] = true;
        cout << cur << " ";
        bf.pop();
        for(int i = 0 ; i < graphs[cur].size() ; i++)
        {
            int temp = graphs[cur][i];
            if(visited[temp] == false)
            {
                bf.push(temp);
            }
        }
    }
    cout << '\n';
    return;
}

int main(void)
{
    int n, m, v;
    cin >> n >> m >> v;
    vector<vector<int>> graphs(n + 1);
    for(int i = 1, a, b; i <= m ; i++)
    {
        cin >> a >> b;
        graphs[a].push_back(b);                 // 노드 간선 연결
        graphs[b].push_back(a);
    }
    dfs(v, graphs);
    bfs(v, graphs);
}