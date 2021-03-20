#include <iostream>
#include <vector>

using namespace std;

int n, p, c, w;
vector<pair<int,int>> tree[10001];
bool visited[10001];
int target = 0;
int maxLength = 0;

void dfs(int node, int length)
{
    bool exist = false;
    for(int i = 0 ; i < tree[node].size() ; i++)    // 자식노드들 dfs 탐색
    {
        int child = tree[node][i].first;
        if(!visited[child])
        {
            exist = true;
            visited[child] = true;
            dfs(child, length + tree[node][i].second);
        }
    }
    if(!exist)                  // 만약 리프노드 라면
    {
        if(length > maxLength)  // 최대길이인지 확인 후
        {
            maxLength = length; // 길이 갱신
            target = node;      // 다음 시작노드 갱신
        }
    }
}

int main(void)
{
    cin >> n;
    for(int i = 0 ; i < n - 1 ; i++)
    {
        cin >> p >> c >> w;
        tree[p].push_back({c,w});   // 트리를 양방향으로 넣어줌
        tree[c].push_back({p,w});
    }

    visited[1] = true;
    dfs(1, 0);              // 루트부터 시작해서 최대 길이(양 끝점 중 하나)인 노드 찾고
    for(int i = 1 ; i <= n ; i++) visited[i] = false;
    
    visited[target] = true; // 해당 노드부터 다시 최대길이인 노드 찾음
    dfs(target, 0);

    cout << maxLength << endl;
}