#include <iostream>
#include <queue>
using namespace std;

int n, m;
char miro[100][100];
bool visited[100][100];

struct Point
{
    int row;
    int col;
};

int main(void)
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m;
    for(int r = 0 ; r < n ; r++)
    {
        for(int c = 0 ; c < m ; c++)
        {
            cin >> miro[r][c];                                  // 미로 정보 입력
            if(miro[r][c] == '0') visited[r][c] = true;         // 길이 아닌 땅을 방문한 곳으로 표시함, 갈 수 없다는 의미
        }
    }
    int answer = 0;                                             // answer 은 최단거리 값이 담길 변수
    queue<pair<Point,int>> q;
    q.push(pair<Point,int>(Point{0, 0}, 1));                    // (0,0) 시작지점부터 길찾기 시작
    while(true)
    {
        pair<Point, int>& cur = q.front();                      // 큐에서 꺼낼 값 (좌표(row,col), 거리)
        Point& pos = cur.first;
        if(pos.row == n - 1 && pos.col == m - 1)                // 만약 이번 좌표가 목적지라면
        {
            answer = cur.second;                                // 이번 거리를 answer 에 넣고 반복 종료
            break;
        }
                                                                // 목적지가 아닐 경우 계속 진행
        visited[pos.row][pos.col] = true;                       // 이번 좌표 방문 처리
        // 상하좌우 4 방향으로 인덱스를 벗어나지 않고 방문하지 않은 길이 있다면 큐에 넣어줌
        if(pos.row - 1 >= 0 && !visited[pos.row - 1][pos.col]) 
            q.push(pair<Point,int>(Point{pos.row-1, pos.col}, cur.second + 1));
        if(pos.row + 1 < n && !visited[pos.row + 1][pos.col]) 
            q.push(pair<Point,int>(Point{pos.row+1, pos.col}, cur.second + 1));
        if(pos.col - 1 >= 0 && !visited[pos.row][pos.col - 1]) 
            q.push(pair<Point,int>(Point{pos.row, pos.col-1}, cur.second + 1));
        if(pos.col + 1 < m && !visited[pos.row][pos.col + 1]) 
            q.push(pair<Point,int>(Point{pos.row, pos.col+1}, cur.second + 1));
        q.pop();
    }

    cout << answer << '\n';
}