#include <iostream>

using namespace std;

int w, h;
int map[50][50];
int dir[3] = {-1, 0, 1};

void dfs(int row, int col)                              // dfs 로 섬 하나씩 처리
{
    if(0 <= row && row < w && 0 <= col && col < h)
        if(map[row][col] == 1)
        {
            map[row][col] = 0;
            for(int r = 0 ; r < 3 ; r++)                // 가로, 세로, 대각선으로 이어진 땅들 하나로 묶음
                for(int c = 0 ; c < 3 ; c++)
                    dfs(row + dir[r], col + dir[c]);
        }
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    while (true)
    {
        cin >> h >> w;
        if(w == 0 && h == 0) break;

        int answer = 0;
        for(int r = 0 ; r < w ; r++)
            for(int c = 0 ; c < h ; c++)
                cin >> map[r][c];

        for(int r = 0 ; r < w ; r++)
            for(int c = 0 ; c < h ; c++)                // 아직 방문하지 않은 땅이 있다면
                if(map[r][c] == 1)                      // 해당 땅에 속하는 섬을 하나로 묶어서 셈
                {
                    answer++;
                    dfs(r, c);
                }

        cout << answer << '\n';
    }
}