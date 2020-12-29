#include <iostream>
#include <queue>

using namespace std;

int N, M;
char miro[100][100];
bool visited[100][100];
int dir[4] = {1, -1, 0, 0};
priority_queue<pair<int, pair<int,int>>> hq;


int main(void)
{
    cin >> M >> N;
    for(int i = 0 ; i < N ; i++) for(int j = 0 ; j < M ; j++)
    {
        cin >> miro[i][j];
    }

    hq.push({0, {0, 0}});

    while(hq.size())
    {
        int r = hq.top().second.first;              // 가장 최소거리인 지점과 거리값을 뽑아내고
        int c = hq.top().second.second;
        int dist = -hq.top().first;
        hq.pop();

        if(r == N-1 && c == M-1)                    // 만약 목적지면 거리(부순 벽의 수) 출력하고 종료
        {
            cout << dist << endl;
            return 0;
        }

        for(int i = 0 ; i < 4 ; i++)                // 그게 아니라면 해당 위치에서 4방향 검사
        {
            int nr = r + dir[i];
            int nc = c + dir[3-i];                  // 인덱스 벗어나거나 이미 큐에 넣어놨던 지점이라면 스킵
            if(nr < 0 || nr >= N || nc < 0 || nc >= M || visited[nr][nc]) continue;
            
            visited[nr][nc] = true;                 // 처음 오는 곳이라면 방문 처리해주고
            hq.push({-(dist + miro[nr][nc] - 48), {nr, nc}});   // 해당 위치의 거리를 큐에 넣어주고 반복
        }
    }
}