#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m, ans;
int box[1000][1000];
int rotten[1000][1000];

int main(void)
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> m >> n;
    for(int r = 0 ; r < n ; r++)
    {
        for(int c = 0 ; c < m ; c++)
        {
            cin >> box[r][c];
        }
    }

    queue<pair<int,int>> q;
    for(int r = 0 ; r < n ; r++)
    {
        for(int c = 0 ; c < m ; c++)
        {
            if(box[r][c] == 1)
            {
                q.push(pair<int,int>(r,c));                 // BFS 시작은 익은 토마토(1) 인 좌표들 모두
            }
        }
    }
    int row,col;
    while(!q.empty())                                       // 더 이상 익힐 수 있는 토마토가 없을때까지
    {
        pair<int,int>& pos = q.front();                     // 이번 토마토
        row = pos.first;                                    //           의 row
        col = pos.second;                                   //           의 column
        int rotDay = rotten[row][col];                      //           의 익어진 날짜
        if(rotDay > ans) ans = rotDay;                      // 경과되는 날짜의 최댓값이 답이 됨
    
        if(row - 1 >= 0 && box[row - 1][col] == 0)          // 만약 다음 위치가 안 익은 토마토라면
        {
            q.push(pair<int,int>(row -1 , col));            // 해당 위치를 큐에 넣어주고
            box[row - 1][col] = 1;                          // 익었다고 표시
            rotten[row - 1][col] = rotDay + 1;              // 해당 위치의 토마토 익은 날짜를 설정해줌
        }
        if(row + 1 < n && box[row + 1][col] == 0) 
        {
            q.push(pair<int,int>(row +1 , col));
            box[row + 1][col] = 1;
            rotten[row + 1][col] = rotDay + 1;
        }
        if(col - 1 >= 0 && box[row][col - 1] == 0)
        {
            q.push(pair<int,int>(row, col - 1));
            box[row][col - 1] = 1;
            rotten[row][col - 1] = rotDay + 1;
        }
        if(col + 1 < m && box[row][col + 1] == 0)
        {
            q.push(pair<int,int>(row, col + 1));
            box[row][col + 1] = 1;
            rotten[row][col + 1] = rotDay + 1;
        }
        q.pop();
    }

    for(int r = 0 ; r < n ; r++)
    {
        for(int c = 0 ; c < m ; c++)
        {
            if(box[r][c] == 0)                              // 만약 다 익혔는데도 안 익은 토마토가 있다면
            {
                ans = -1;                                   // -1 출력
                break;
            }
        }
        if(ans == -1) break;
    }
    cout << ans << '\n';
}