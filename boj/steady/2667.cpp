#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
char map[25][25];                       // 지도 정보
int dir[4] = {1, -1, 0, 0};             // 상하좌우 방향 깔끔하게

int dfs(int row, int col)
{
    if(map[row][col] == '0') return 0;  // 빈 곳은 그냥 종료
    if(row < 0 || row >= n || col < 0 || col >= n) return 0; // 이외에도 인덱스 초과 시 그냥 종료

    map[row][col] = '0';                // 해당 집을 방문했다고 표시
    int ret = 1;                        // 집의 수 1
    for(int i = 0 ; i < 4 ; i++)
    {
        ret += dfs(row + dir[i], col + dir[3 - i]); // 같은 단지에 속한 집들을 재귀적으로 검사하여
    }
    return ret;                         // 단지에 속한 전체 집의 수를 반환
}

int main(void)
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;
    for(int r = 0 ; r < n ; r++)
    {
        for(int c = 0 ; c < n ; c++)
        {
            cin >> map[r][c];
        }
    }
    int ans = 0;                                    // 단지의 수
    vector<int> numbers;                            // 단지별로 속한 집의 수
    for(int r = 0 ; r < n ; r++)
    {
        for(int c = 0 ; c < n ; c++)
        {
            if(map[r][c] != '0')                    // 만약 검사하지 않은 단지가 있다면
            {
                int temp = dfs(r, c);               // 단지를 싹 검사해주고
                numbers.push_back(temp);            // 단지에 속한 집의 수를 넣어주고
                ans++;                              // 단지의 수 증가
            }
        }
    }
    sort(numbers.begin(), numbers.end());           // 단지별 집의 수 정렬 후 
    cout << ans << '\n';        
    for(int i = 0 ; i < numbers.size() ; i++)       // 오름차순 출력
    {
        cout << numbers[i] << '\n';
    }
}