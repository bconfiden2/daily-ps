#include <iostream>

using namespace std;

int n;
int yes[100][100];
int no[100][100];
int dir[4] = {1, -1, 0, 0};         // 상하좌우 4방향

void dfsYes(int r, int c, int target)                       // DFS 함수
{
    if(r < 0 || r >= n || c < 0 || c >= n) return;          // 인덱스 벗어난 위치면 종료
    if(yes[r][c] == 0 || yes[r][c] != target) return;       // 이미 검사했던 곳(0)이거나, 다른 구역일 경우 종료
    yes[r][c] = 0;                                          // 방문 처리(0)
    for(int i = 0 ; i < 4 ; i++)                            // 상하좌우 4방향에 대해서 탐색
    {
        dfsYes(r + dir[i], c+ dir[3-i], target);
    }
}

void dfsNo(int r, int c, int target)                        // 원리는 위와 동일한데
{                                                           // RGB 맵 정보만 달라서 그냥 따로 만듦
    if(r < 0 || r >= n || c < 0 || c >= n) return;
    if(no[r][c] == 0 || no[r][c] != target) return;
    no[r][c] = 0;
    for(int i = 0 ; i < 4 ; i++)
    {
        dfsNo(r + dir[i], c+ dir[3-i], target);
    }
}

int main(void)
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n;
    char temp;
    for(int r = 0 ;r < n ; r++)
    {
        for(int c = 0 ; c < n ; c++)                // N * N 개의 RGB 정보들을 입력받음
        {
            cin >> temp;
            if(temp == 'R')                         // 각각 RGB 에 대해서
            {
                no[r][c] = 1;                       // 적록색약이 아닌 사람은 정상적으로 구별
                yes[r][c] = 1;                      // 적록색약인 사람은 R 과 G 를 같은 값으로
            }
            else if(temp == 'G')
            {
                no[r][c] = 2;
                yes[r][c] = 1;
            }
            else
            {
                no[r][c] = 3;
                yes[r][c] = 3;
            }
        }
    }
    int numYes = 0;
    int numNo = 0;
    for(int r = 0 ;r < n ; r++)
    {
        for(int c = 0 ; c < n ; c++)                // DFS 로 구역 확인
        {
            if(yes[r][c] != 0)                      // 적록색약인 사람에 대해서
            {                                       // 적록색약 버젼 DFS
                dfsYes(r, c, yes[r][c]);
                numYes++;
            }
            if(no[r][c] != 0)                       // 적록색약이 아닌 사람에 대해서도
            {                                       // 아닌 버젼 DFS
                dfsNo(r, c, no[r][c]);
                numNo++;
            }
        }
    }
    cout << numNo << " " << numYes << '\n';
}