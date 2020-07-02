#include <iostream>

using namespace std;

bool map[50][50];

void dfs(int row, int col)
{
    if(row < 0 || row >= 50) return;
    if(col < 0 || col >= 50) return;

    if(!map[row][col])
    {
        return;
    }
    map[row][col] = false;

    dfs(row - 1, col);
    dfs(row + 1, col);
    dfs(row, col - 1);
    dfs(row, col + 1);
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