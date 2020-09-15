#include <iostream>
#include <vector>

using namespace std;

int n, temp, maxi, answer;
int map[100][100];
bool tmap[100][100];
int dir[4] = {-1, 1, 0, 0};

void dfs(int r, int c)
{
    if(0 <= r && r < n && 0 <= c && c < n)      // 인덱스 검사
    {
        if(tmap[r][c])                          // 이어지는 영역이라면
        {
            tmap[r][c] = false;                 // 방문처리
            for(int i = 0 ; i < 4 ; i++)        // 4방향으로 이어지는게 더 있는지 확인
            {
                dfs(r + dir[i], c + dir[3-i]);
            }
        }
    }
}

int main(void)
{
    cin >> n;
    for(int r = 0 ; r < n ; r++)
        for(int c = 0 ; c < n ; c++)
        {
            cin >> temp;
            map[r][c] = temp;
            if(temp > maxi) maxi = temp;
        }

    for(int height = 2 ; height < maxi ; height++)              // 가능한 장마의 높이를 전부 탐색
    {
        for(int r = 0 ; r < n ; r++)
            for(int c = 0 ; c < n ; c++)
            {
                if(map[r][c] <= height) tmap[r][c] = false;     // dfs 에 사용할 tmap 을 매번 적절하게 초기화
                else tmap[r][c] = true;
            }
        
        temp = 0;
        for(int r = 0 ; r < n ; r++)                            // dfs
            for(int c = 0 ; c < n ; c++)
            {
                if(tmap[r][c])
                {
                    dfs(r, c);
                    temp++;
                }
            }

        if(temp > answer) answer = temp;                        // 안전 영역 갯수 최댓값 갱신
    }

    cout << answer << endl;
}