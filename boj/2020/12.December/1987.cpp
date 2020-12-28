#include <iostream>

using namespace std;

int R, C, answer;
char board[20][20];
bool checked[26];
int dir[4] = {1, -1, 0, 0};

void dfs(int row, int col, int depth)
{
    answer = (depth > answer ? depth : answer);     // 현재 방문한 위치까지의 거리 갱신

    for(int i = 0 ; i < 4 ; i++)                    // 상하좌우 4방향에 대해서 검사
    {
        int nX = row + dir[i];
        int nY = col + dir[3-i];
                                                    // 인덱스 벗어나거나 이미 방문한 알파벳이면 재귀 X
        if(nX < 0 || nX >= R || nY < 0 || nY >= C || checked[board[nX][nY]-65]) continue;

        checked[board[nX][nY]-65] = true;           // 백트래킹
        dfs(nX, nY, depth+1);                       // 새로운 알파벳일 경우에만 재귀호출로 한칸 움직임 처리
        checked[board[nX][nY]-65] = false;
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> R >> C;

    for(int i = 0 ; i < R ; i++)
    {
        for(int j = 0 ; j < C ; j++)
        {
            cin >> board[i][j];
        }
    }

    checked[board[0][0] - 65] = true;       // 시작점 알파벳 방문처리 한 후 DFS 시작
    dfs(0, 0, 1);
    cout << answer << endl;                 // DFS 내에서 갱신된 최댓값 출력
}