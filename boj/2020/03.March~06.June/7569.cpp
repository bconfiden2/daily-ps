#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m, h, ans, number, data;
int box[100][100][100];
int dr[6] = {1, -1, 0, 0, 0, 0};
int dc[6] = {0, 0, 1, -1, 0, 0};                              // 상,하,좌,우, 위,아래 에 대한 방향정보
int dd[6] = {0, 0, 0, 0, 1, -1};

struct Point
{
    int first;
    int second;
    int third;
};

int main(void)
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> m >> n >> h;
    queue<Point> q;
    for(int d = 0 ; d < h ; d++)
    {
        for(int r = 0 ; r < n ; r++)
        {
            for(int c = 0 ; c < m ; c++)
            {
                cin >> data;
                box[r][c][d] = data;
                if(data == 1) q.push(Point{r, c, d});           // BFS 시작 노드들 푸시
                if(data == 0) number++;                         // 덜 익은 토마토 갯수
            }
        }
    }
    number += q.size();                                         // 노드 하나당 number 를 빼주는데,
    int row,col,dep;                                            // 맨 처음 시작 노드들은 1이기 때문에 카운트 따로 해줌
    while(!q.empty())
    {
        for(int s = q.size() ; s-- > 0 ; q.pop(), number--)     // 하루 단위로 처리함 (현재 큐에 들어있는것들이 하루)
        {
            row = q.front().first;
            col = q.front().second;
            dep = q.front().third;

            for(int i = 0, r,c,d ; i < 6 ; i++)
            {
                r = row + dr[i];                                                // 각자의 방향에 맞게 이동 (dr, dc, dd)
                c = col + dc[i];
                d = dep + dd[i];
                if((0 <= r && r < n) && (0 <= c && c < m) && (0 <= d && d < h)) // 인덱스 검사 하고
                {
                    if(box[r][c][d] == 0)                                       // 덜 익은 토마토 일 경우
                    {
                        q.push(Point{r, c, d});                                 // 해당 노드 푸시하고
                        box[r][c][d] = 1;                                       // 익힘 처리
                    }
                }
            }
        }
        ans++;                                                      // 날짜 1 증가
    }
    if(number == 0) cout << ans - 1 << '\n';                        // 모든 토마토가 익혀졌다면 number 가 0 이 될 것임
    else cout << -1 << '\n';
}