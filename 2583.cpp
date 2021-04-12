#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int m, n, k;
int lx, ly, rx, ry;
int dir[4] = {1, -1, 0, 0};
bool area[100][100];
vector<int> answer;

int dfs(int r, int c)               // 특정 영역에서 연결된 모든 영역을 칠해주고, 영역 갯수 반환
{
    int ret = 1;                    // 현재 위치 방문했다는 표시

    for(int i = 0 ; i < 4 ; i++)    // 4방향에 대해서
    {
        int nr = r + dir[i];
        int nc = c + dir[3-i];
        if(nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
        if(area[nr][nc]) continue;
        area[nr][nc] = true;        // 방문처리 해준 뒤
        ret += dfs(nr, nc);         // 재귀호출로 뒤에 연결된 영역의 수를 현재 위치에 더해줌
    }

    return ret;                     // 칠한 영역 수 반환
}

int main(void)
{
    cin >> m >> n >> k;
    for(int i = 0 ; i < k ; i++)
    {
        cin >> lx >> ly >> rx >> ry;
        for(int r = ly ; r < ry ; r++)
        {
            for(int c = lx ; c < rx ; c++)
            {
                area[r][c] = true;          // 100 x 100 이기 때문에, 영역에 해당하는 모든 인덱스를 직접 칠한다
            }
        }
    }  

    for(int i = 0 ; i < m ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            if(!area[i][j])                 // 남은 영역이 있으면
            {
                area[i][j] = true;
                answer.push_back(dfs(i, j));// 해당 영역부터 dfs 돌려서 싹 채워주고 채운 영역의 수 확인
            }
        }
    }

    sort(answer.begin(), answer.end());     // 정렬 후 사이즈 및 원소들 출력

    cout << answer.size() << endl;
    for(int i = 0 ; i < answer.size() ; i++)
    {
        cout << answer[i] << " ";
    }
    cout << endl;
}