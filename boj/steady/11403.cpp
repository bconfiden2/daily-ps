#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
bool linked[100][100];

int main(void)
{
    cin >> n;
    for(int r = 0 ; r < n ; r++)
    {
        for(int c = 0 ; c < n ; c++)
        {
            cin >> linked[r][c];                    // 연결 행렬 입력 받음
        }
    }
    vector<vector<int>> v(n);
    for(int r = 0 ; r < n ; r++)
    {
        for(int c = 0 ; c < n ; c++)
        {
            if(linked[r][c])                        // 노드 간 연결(단방향) 처리
            {
                v[r].push_back(c);
            }
        }
    }
    for(int i = 0 ; i < n ; i++)                    // (i,j) 각각마다 연결여부 확인
    {
        for(int j = 0 ; j < n ; j++)
        {
            bool able = false;
            queue<int> q;
            vector<bool> visited(n, false);
            for(int k = 0 ; k < v[i].size() ; k++)  // 첫 BFS 시작을 그냥 i 로 줘버리면
            {                                       // i == j 의 경우 전부 연결처리되버리기 때문에
                q.push(v[i][k]);                    // i 에 연결된 노드들을 넣어주면서 시작
                visited[v[i][k]] = true;
            }
            while(!q.empty())
            {
                int cur = q.front();
                if(cur == j)                        // j 에 도착시 종료
                {
                    able = true;
                    break;
                }
                visited[cur] = true;                // 이번 노드 방문 처리
                for(int k = 0 ; k < v[cur].size() ; k++)
                {
                    if(!visited[v[cur][k]])         // 방문하지 않은 노드들만 푸시함으로써
                    {                               // 도착이 불가능할 경우 q.empty() 를 통해 빠져나갈 수 있게
                        q.push(v[cur][k]);          
                    }
                }
                q.pop();
            }
            cout << able << " ";
        }
        cout << '\n';
    }
}