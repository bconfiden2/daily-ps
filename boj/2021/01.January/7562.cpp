#include <iostream>
#include <queue>

using namespace std;

int tc;
int length;
int startX, startY;
int targetX, targetY;
int dirX[8] = {2, 2, -2, -2, 1, 1, -1, -1};             // 나이트의 8방향 배열
int dirY[8] = {1, -1, 1, -1, 2, -2, 2, -2};

int main(void)
{
    cin >> tc;
    for(int t = 0 ; t < tc ; t++)
    {
        cin >> length;                                  // 체스판 크기 입력
        cin >> startX >> startY >> targetX >> targetY;  // 시작점과 도착점 입력
        bool visited[length][length];
        for(int r = 0 ; r < length ; r++)               // 방문여부 배열 초기화
            for(int c = 0 ; c < length ; c++)
                visited[r][c] = false;
        queue<pair<int, int>> q;
        q.push({startX, startY});                       // 큐에 시작점 넣고
        visited[startX][startY] = true;                 // 방문처리 해준 뒤
        bool exit = false;
        int count = 0;
        while(!exit)                                    // 도착점에 도달할때까지 반복
        {
            int sz = q.size();                          // 나이트가 한번 이동했을때 큐에 들어간 모든 위치 검사
            for(int _ = 0 ; _ < sz ; _++)
            {
                int curX = q.front().first;
                int curY = q.front().second;
                q.pop();
                if(curX == targetX && curY == targetY)  // 목적지라면 나이트이동횟수 출력하고 종료
                {
                    cout << count << endl;
                    exit = true;
                    break;
                }
                for(int i = 0 ; i < 8 ; i++)            // 목적지가 아니면 8 방향에 대해서 이동
                {
                    int nextX = curX + dirX[i];
                    int nextY = curY + dirY[i];
                    if(nextX < 0 || nextX >= length) continue;  // 인덱스를 벗어나거
                    if(nextY < 0 || nextY >= length) continue;
                    if(visited[nextX][nextY]) continue;         // 이미 방문했던 곳이라면 스킵
                    visited[nextX][nextY] = true;               // 처음 가는 곳이라면 방문처리해준 뒤
                    q.push({nextX, nextY});                     // 큐에 넣어줌
                }
            }
            count++;                                    // 나이트의 n 번째 이동에 해당하는 모든 위치를 처리한 뒤 횟수 증가
        }
    }
}
