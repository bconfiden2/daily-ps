#include <iostream>

using namespace std;

int T, n;
int visited[100001];        // -1 은 비순환, 0 은 미방문, 1 은 dfs 도중 방문, 2 는 순환구조 형성
int parent[100001];

int find(int cur)                           // dfs 로 연결된 노드들 탐색
{
    if(visited[cur] == 1) return cur;                       // dfs 탐색 중간부터 순환되기 시작한 경우, 해당 노드까지 순환처리하기 위해 인덱스 반환
    if(visited[cur] == -1 || visited[cur] > 1) return -1;   // 이미 순환 형성된 노드를 방문하거나, 불가능한 노드를 방문한 경우엔 비순환 처리

    visited[cur] = 1;                       // 이번 dfs 탐색에서 방문했다고 처리
    int temp = find(parent[cur]);           // 연결된 노드로 재귀적으로 들어가서 결과 받아옴
    if(temp == -1)                          // 이번 노드가 순환구조에 속하지 않는다면
    {
        visited[cur] = -1;                  // 비순환인 -1 로 처리해준 뒤
        return -1;                          // 그 위의 호출들 역시 비순환으로 반환
    }
    else                                    // 이번 노드가 순환구조에 속할 경우
    {
        visited[cur] = 2;                   // 순환인 2 로 처리해준 뒤
        return (temp == cur ? -1 : temp);   // 중간부터 순환되기 시작한 노드까지만 순환 처리, 그 위로는 비순환 반환
    }
}

int main(void)
{
    cin >> T;
    while(T--)
    {
        int cnt = 0;
        cin >> n;
        for(int i = 1 ; i <= n ; i++)
        {
            cin >> parent[i];
            visited[i] = (i == parent[i] ? 2 : 0);;
        }
        for(int i = 1 ; i <= n ; i++)
        {
            if(visited[i] == 0)         // 미방문 노드에 대해서만 dfs 탐색
            {
                find(i);
            }
        }
        for(int i = 1 ; i <= n ; i++) if(visited[i] == -1) cnt++;

        cout << cnt << endl;
    }
}