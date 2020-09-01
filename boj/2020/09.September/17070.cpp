#include <iostream>

using namespace std;

int n, temp;
int map[17][17];
int answer;

void dfs(int row, int col, int state)       // 왼쪽 파이프는 항상 유효하기 때문에 고려할 필요 없음, 오른쪽 파이프의 위치만 고려
{
    if(map[row][col] == 1) return;          // 만약 다음 위치가 벽이면 종료
    if(row > n || col > n) return;          // 인덱스 초과 시 종료
    if(state == 3)                          // 대각선으로 내려왔을 경우는 위쪽과 왼쪽도 벽일 경우 종료
        if(map[row-1][col] == 1 || map[row][col-1] == 1) return;

    if((row == n && col == n))              // 만약 끝점에 도달했을 경우는
    {                                       // 경로 카운트 증가시키고 종료
        answer++;
        return;
    }
    
    if(state == 1)                          // 가로로 왔을 땐
    {
        dfs(row, col + 1, state);           // 두 가지 방법으로 일단 보내봄 (유효성 검사는 앞에서 하므로)
        dfs(row + 1, col + 1, 3);
    }
    else if(state == 2)                     // 세로
    {
        dfs(row + 1, col, state);
        dfs(row + 1, col + 1, 3);
    }
    else                                    // 대각선
    {
        dfs(row, col + 1, 1);
        dfs(row + 1, col, 2);
        dfs(row + 1, col + 1, 3);
    }
}

int main()
{
    cin >> n;
    for(int r = 1 ; r <= n ; r++)
        for(int c = 1 ; c <= n ; c++)
            cin >> map[r][c];
                                            // 처음에 (1,1) (1,2) 에서 시작하게 될 경우에는
    dfs(1, 3, 1);                           // 가로로 보내고
    dfs(2, 3, 3);                           // 대각선으로 보낼 수 있다

    cout << answer << endl;
}