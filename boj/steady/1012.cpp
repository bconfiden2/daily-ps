#include <iostream>

using namespace std;

bool map[50][50];

// 돌면서 상하좌우 탐색
void dfs(int row, int col)
{
    // 인덱스 에러 방지
    if(row < 0 || row >= 50) return;
    if(col < 0 || col >= 50) return;
    
    // 이미 검사했거나 땅이 아닐 경우 제외
    if(!map[row][col])
    {
        return;
    }
    // 검사했다고 표시
    map[row][col] = false;
    dfs(row + 1, col); // 상
    dfs(row - 1, col); // 하
    dfs(row, col - 1); // 좌
    dfs(row, col + 1); // 우
}

int main(void)
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int tc;
    cin >> tc;
    for(int t = 0 ; t < tc ; t++)
    {
        int m, n, k;
        cin >> m >> n >> k;
        
        for(int i = 0 ; i < k ; i++)
        {
            int x, y;
            cin >> x >> y;
            map[y][x] = true;
        }
        // 검사하지 않은 땅이 있으면 연결된 땅 모두 검사하는 dfs
        int number = 0;
        for(int row = 0 ; row < n ; row++)
        {
            for(int col = 0 ; col < m ; col++)
            {
                if(map[row][col])
                {
                    number++;
                    dfs(row, col);
                }
            }
        }

        cout << number << '\n';
    }
}