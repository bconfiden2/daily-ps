#include <iostream>

using namespace std;

int R, C, T, answer;
int map[100][100];
int dir[4] = {1, -1, 0, 0};     // 4방향 정보

void bt(int r, int c, int score, int depth)         // dfs 로 경로 검사 + 백트래킹으로 고구마 관리
{
    if(depth == T)                                  // 가능한 거리 다 움직여봤을 때 최대값 갱신
    {
        if(score > answer) answer = score;
        return;
    }
    for(int i = 0 ; i < 4 ; i++)                    // 현재 위치에서 4방향으로 또 한칸 움직임
    {
        int nr = r + dir[i];
        int nc = c + dir[3-i];
        if(nr>=0 && nr < R && nc >= 0 && nc < C && map[nr][nc] != -1)
        {
            bool tmp = false;
            if(map[nr][nc] == 1)                    // 고구마 위치면 먹어치우고
            {
                map[nr][nc] = 0;
                tmp = true;
            }
            bt(nr, nc, score + tmp, depth+1);       // 다음 칸으로 또 움직임
            if(tmp) map[nr][nc] = 1;                // 고구마가 있던 자리라면 되돌려놓음
        }
    }
}

int main(void)
{
    cin >> R >> C >> T;

    char tmp;
    int sr, sc;
    for(int r = 0 ; r < R ; r++)
    {
        for(int c = 0 ; c < C ; c++)
        {
            cin >> tmp;
            if(tmp == 'G') sr=r, sc=c;              // 시작점 지정, 빈칸은 기본 0
            else if(tmp == 'S') map[r][c] = 1;      // 고구마는 1
            else if(tmp == '#') map[r][c] = -1;     // 장애물은 -1
        }
    }
    
    bt(sr, sc, 0, 0);
    cout << answer << endl;
}