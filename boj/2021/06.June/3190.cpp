#include <iostream>
#include <queue>

using namespace std;

int N, K, L;
int board[100][100];
int dir[4] = {0, -1, 0, 1};         // 뱀의 4방향

int main(void)
{
    cin >> N >> K;
    for(int i = 0, r, c ; i < K ; i++)
    {
        cin >> r >> c;
        board[r-1][c-1] = -1;
    }

    cin >> L;
    queue<pair<int,int>> q;
    for(int i = 0, X ; i < L ; i++)
    {
        char C;
        cin >> X >> C;
        q.push({X, (C == 'L' ? 1 : -1)});
    }

    deque<pair<int,int>> snake;
    board[0][0] = 1;
    snake.push_front({0,0});
    int cnt = 0;
    int curdir = 0;
    while(true)
    {
        int nextR = snake.front().first + dir[curdir];                  // 뱀머리의 다음 위치
        int nextC = snake.front().second + dir[3-curdir];
        if(nextR < 0 || nextR >= N || nextC < 0 || nextC >= N) break;   // 벽에 부딪히면 종료
        
        if(board[nextR][nextC] == 0)                                    // 사과를 먹지 않을 경우
        {
            board[snake.back().first][snake.back().second] = 0;
            snake.pop_back();
        }
        else if(board[nextR][nextC] != -1) break;                       // 자기 몸에 부딪힌 경우
        
        snake.push_front({nextR, nextC});                               // 뱀 머리 움직임 처리
        board[nextR][nextC] = 1;

        cnt++;                                                          // 게임 시간 1초 증가
        if(q.size() && cnt == q.front().first)                          // 만약 뱀이 회전했다면
        {
            curdir = (curdir+4+q.front().second) % 4;                   // 뱀의 현재 방향 업데이트
            q.pop();
        }
    }
    cout << cnt+1 << endl;
}