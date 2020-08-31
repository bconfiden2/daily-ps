#include <iostream>

using namespace std;

int n, m, answer;
int map[8][8];                  // 처음에 들어온 지도 정보를 담을 배열
int tmap[8][8];                 // 매 반복마다 재사용할 임시 배열
int dir[4] = {-1, 1, 0, 0};     // dfs 에서 상하우좌 4방향 처리

void dfs(int r, int c)
{
    if(r < 0 || r >= n || c < 0 || c >= m) return;  // 인덱스 검사 후

    tmap[r][c] = -1;                                // 해당 위치 방문 처리
    for(int i = 0 ; i < 4 ; i++)                    
    {
        if(tmap[r+dir[i]][c+dir[3-i]] == 0)         // 상하우좌 4방향을 검사했을 때 연결되어 있는 곳은
            dfs(r+dir[i],c+dir[3-i]);               // 재귀 호출해서 모두 방문처리
    }
}

int main(void)
{
    cin >> n >> m;
    for(int r = 0 ; r < n ; r++)
        for(int c = 0 ; c < m ; c++)
            cin >> map[r][c];
            
    for(int p1 = 0 ; p1 < n * m ; p1++)                 // 최대 64 * 64 * 64 이므로 완전 탐색해서 모든 경우의 수 찾음
    {
        if(map[p1 / m][p1 % m] != 0) continue;          // 벽을 세울 수 없는 곳이라면 스킵
        for(int p2 = p1 + 1 ; p2 < n * m ; p2++)        // p2 는 p1 다음 지점부터 검사
        {
            if(map[p2 / m][p2 % m] != 0) continue;
            for(int p3 = p2 + 1 ; p3 < n * m ; p3++)    // p3 는 p2 다음 지점부터 검사
            {
                if(map[p3 / m][p3 % m] != 0) continue;

                for(int i = 0 ; i < n ; i++)
                    for(int j = 0 ; j < m ; j++)
                        tmap[i][j] = map[i][j];         // 기존 맵을 임시맵에 매번 복사
                
                tmap[p1 / m][p1 % m] = 1;               // 벽으로 선정한 3군데 표시
                tmap[p2 / m][p2 % m] = 1;
                tmap[p3 / m][p3 % m] = 1;
                
                for(int i = 0 ; i < n ; i++)
                    for(int j = 0 ; j < m ; j++)
                        if(tmap[i][j] == 2)
                            dfs(i, j);                  // 바이러스가 옮겨갈 수 있는 곳은 모두 -1 로 처리

                int temp = 0;
                for(int i = 0 ; i < n ; i++) 
                    for(int j = 0 ; j < m ; j++) 
                        if(tmap[i][j] == 0) temp++;     // 바이러스에 감염되지 않은 공간 카운트
                if(temp > answer) answer = temp;        // 최댓값 갱신
            }
        }
    }

    cout << answer << endl;
}