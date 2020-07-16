#include <iostream>
#include <algorithm>
#include <queue>
#define Point pair<int,int>

using namespace std;

int n;
int space[20][20];      // 실제 물고기들 정보
int visited[20][20];    // 각 위치까지의 거리에 대한 정보
Point shark_pos;        // 상어의 현재 위치
int shark_size = 2;     // 상어 현재 크기
int eatten = 0;         // 상어가 현재 사이즈에서 먹은 물고기 수
int timer = 0;
int dir[4] = {1, -1, 0, 0};

void distance()     // 물고기 현재 위치로부터 NxN 크기의 각 위치까지의 최단거리를 갱신하는 함수
{
    for(int i = 0 ; i < n ; i ++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            visited[i][j] = 0;                              // 거리 정보 초기화
            if(space[i][j] > shark_size)                    // 지나갈 수 없는 칸에 대해서는 1000 으로 설정
                visited[i][j] = 1000;
        }
    }
    int dist = 0;
    queue<Point> q;                                     // 각 위치에 대해서 BFS
    q.push(shark_pos);                                      // 상어의 현재 위치부터 시작해서
    visited[shark_pos.first][shark_pos.second] = 1000;
    while(!q.empty())                                       // 상어가 도착할 수 있는 곳은 전부 탐색
    {
        int size = q.size();
        for(int i = 0 ; i < size ; i++)
        {
            Point temp = q.front();
            for(int j = 0, r, c ; j < 4 ; j++)
            {
                r = temp.first + dir[j];
                c = temp.second + dir[3 - j];
                if(0 <= r && r < n && 0 <= c && c < n)
                {
                    if(visited[r][c] == 0)
                    {
                        q.push(Point(r,c));
                        visited[r][c] = dist + 1;
                    }
                }
            }
            q.pop();
        }
        dist++;
    }
    for(int r = 0 ; r < n ; r++)
    {
        for(int c = 0 ; c < n ; c++)
        {
            if(visited[r][c] == 0) visited[r][c] = 1000;        // 만약 0 인 칸이 있으면, 도달할 수 없는 곳이라는 뜻이기 때문에 1000 으로 설정
        }
    }
}

int check()               // 물고기를 먹을지, 못 먹는지 체크해서 처리해주는 함수
{
    int cur_time = 1000, x, y;
    distance();                                                     // 현재 물고기 위치에서 각 위치까지의 최단거리 업데이트
    for(int r = 0 ; r < n ; r++)
    {
        for(int c = 0 ; c < n ; c++)
        {
            if(space[r][c] != 0 && space[r][c] < shark_size)            // 먹을 수 있는 물고기 중에
            {
                if(visited[r][c] < cur_time)                            // 가장 최단거리에 있는 물고기를 선택
                {                                                       // 왼위에서 오른아래로 탐색하기 때문에, 같은 거리의 물고기에 대한 조건 충족
                    x = r;
                    y = c;
                    cur_time = visited[r][c];
                }
            }
        }
    }

    if(cur_time == 1000) return 0;                                  // 먹을 수 있는 물고기가 없을 경우 cur_time 이 업데이트 되지 않아서 1000 이 유지된다.
                                                                // 물고기를 먹을 수 있다면
    timer += cur_time;                                              // 해당 위치까지 가는 시간만큼 더해주고
    shark_pos = Point(x,y);                                         // 상어의 위치를 옮겨주고
    space[x][y] = 0;                                                // 해당 위치의 물고기를 없애주고
    eatten++;                                                       // 먹은 횟수 1 증가시켜주는데
    if(eatten == shark_size)                                        // 만약 자신의 크기와 같은 수의 물고기를 먹은 상태라면
    {
        shark_size++;                                                   // 물고기 크기 증가시켜줌
        eatten = 0;
    }
    return 1;                                                       // 다시 반복
}

int main(void)
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;
    for(int r = 0 ; r < n ; r++)
    {
        for(int c = 0 ; c < n ; c++)
        {
            cin >> space[r][c];
            if(space[r][c] == 9)
            {
                shark_pos = Point(r,c);                     // 상어의 위치를 업데이트 시켜주고
                space[r][c] = 0;                            // 상어는 움직일 예정이므로 빈칸인 0 으로 표시
            }
        }
    }

    while(check()) {}                                       // 더 이상 먹을 수 있는 물고기가 없을 때 까지 반복

    cout << timer << '\n';
}