#include <iostream>
#include <queue>

using namespace std;

int n, m;
char map[1001][1001];
bool visited[1001][1001];           // 벽을 안 깨고 온 방문자들과
bool broke_visited[1001][1001];     // 벽을 꺠고 온 방문자들에 대해서 따로 관리
int dir[4] = {1, -1, 0, 0};
int answer = 10e8;

int bfs()
{
    if(n == 1 && m == 1) return 1;
    visited[1][1] = true;
    queue<pair<pair<int,int>, bool>> q;             // 현재 위치와 벽을 깬 상태인지에 대해서 저장
    q.push({{1,1}, false});                         // (1,1) 에서 벽 안 깬 상태로 출발

    int d = 1;                                      // 시작점도 거리에 포함
    while(q.size())
    {
        int sz = q.size();
        for(int i = 0 ; i < sz ; i++)                               // 현재 거리에 있는 노드들에 대해서 확인
        {
            pair<pair<int, int>, int> cur = q.front();
            q.pop();
            for(int k = 0 ; k < 4 ; k++)                            // 노드마다 4방향 확인해서
            {
                int nextR = cur.first.first + dir[k];
                int nextC = cur.first.second + dir[3-k];
                bool has_broken = cur.second;
                if(nextR == n && nextC == m) return d+1;
                if(nextR > 0 && nextR <= n && nextC > 0 && nextC <= m)
                {
                    if(has_broken)                                  // 이미 벽을 꺠고 온 상태라면
                    {
                        if(map[nextR][nextC] == '1')                // 벽에 마주칠 경우 두개는 못 뚫으니 스킵
                        {
                            continue;
                        }
                        else if(!broke_visited[nextR][nextC])       // 하지만 다른 벽을 깨고 온 노드가 방문하지 않았다면
                        {
                            broke_visited[nextR][nextC] = true;     // 처리해주고 큐에 넣어줌
                            q.push({{nextR, nextC}, true});
                        }
                    }
                    else                                            // 벽을 깨지 않은 상태라면
                    {
                        if(map[nextR][nextC] == '1')                // 벽을 만났을 때
                        {
                            has_broken = true;                      // 벽을 깨주고 깬 방문자로 처리
                            broke_visited[nextR][nextC] = true;
                            q.push({{nextR, nextC}, true});
                        }
                        else if(!visited[nextR][nextC])             // 그 외에는 일반 방문자로 처리
                        {
                            visited[nextR][nextC] = true;
                            q.push({{nextR, nextC}, false});
                        }
                    }
                }
            }
        }
        d++;
    }
    return -1;
}

int main(void)
{
    cin >> n >> m;
    for(int r = 1 ; r <= n ; r++)
    {
        for(int c = 1 ; c <= m ; c++)
        {
            cin >> map[r][c];
            visited[r][c] = false;
            broke_visited[r][c] = false;
        }
    }
    
    cout << bfs() << endl;
}