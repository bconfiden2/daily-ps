#include <iostream>

#define ull unsigned long long

using namespace std;

int H, W, L;
char grid[200][200];
pair<int,int> dir[8] = {{-1,0},{1,0},{0,-1},{0,1},{-1,-1},{-1,1},{1,1},{1,-1}}; // 8방향
string target;
ull dp[200][200][100];
ull answer;

void dfs(int r, int c, int depth)                   // 이번 depth(단어 인덱스) 에 맞는 dp 값
{
    if(depth == L-1)
    {
        dp[r][c][depth] = 1;
        return;
    }

    ull value = 0;                                  // 이번 dp 값을 담을 변수
    for(int i = 0 ; i < 8 ; i++)
    {
        int nr = r + dir[i].first;
        int nc = c + dir[i].second;
        if(nr >= 0 && nr < H && nc >= 0 && nc < W)  // 8방향에 대해서 검사하면서
        {
            if(grid[nr][nc] == target[depth+1])     // 알맞은 문자열이 나온다면
            {
                if(dp[nr][nc][depth+1] == -1)       // 이전에 방문하지 못했던 위치일 경우에만
                {
                    dfs(nr, nc, depth+1);           // dfs 새로 탐색해주고
                }
                value += dp[nr][nc][depth+1];       // 기존에 방문했거나 새로 탐색 완료한 dp 값을 총합에 더해줌
            }
        }
    }

    dp[r][c][depth] = value;                        // 이번 dp 값 업데이트
}

int main(void)
{
    cin >> H >> W >> L;
    for(int r = 0 ; r < H ; r++)
    {
        for(int c = 0 ; c < W ; c++)
        {
            cin >> grid[r][c];
            for(int i = 0 ; i < 100 ; i++) dp[r][c][i] = -1;    // dp 배열 -1 로 초기화
        }
    }
    cin >> target;
    
    for(int r = 0 ; r < H ; r++)
    {
        for(int c = 0 ; c < W ; c++)
        {
            if(grid[r][c] == target[0])                         // 가능한 모든 단어 시작 지점부터 dfs 탐색
            {
                dfs(r, c, 0);
                answer += dp[r][c][0];
            }
        }
    }

    cout << answer << endl;
}