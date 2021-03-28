#include <iostream>

using namespace std;

int N, M, count, hour;
int map[101][101];
bool air[101][101];
int dir[4] = {1, -1, 0, 0};

void dfs(int r, int c)
{
    air[r][c] = true;
    for(int i = 0 ; i < 4 ; i++)        // 4방향 검사해서 연결된 공기들 전부 외부공기로 처리
    {
        int nR = r + dir[i], nC = c + dir[3-i];
        if(nR <= 0 || nR > N || nC <= 0 || nC > M) continue;
        if(map[nR][nC] == 1 || air[nR][nC]) continue;
        dfs(nR, nC);
    }
}

void reset()                            // 매 시간마다 치즈가 녹으면서 공기가 어떻게 바뀌는지
{
    for(int r = 1 ; r <= N ; r++)
        for(int c = 1 ; c <= M ; c++)
            air[r][c] = false;          // 공기 위치 전체 초기화해준뒤에
            
    dfs(1, 1);                          // 바깥 공기부터 dfs 로 연결된 모든 공기 처리
}

void check(int r, int c)                // 치즈가 녹아야할지 확인 후 처리
{
    int meltCount = 0;
    for(int i = 0 ; i < 4 ; i++)        // 4방향에 대해서 공기랑 접한 지점의 수 확인
        if(air[r + dir[i]][c + dir[3-i]]) meltCount++;
    
    if(meltCount >= 2)                  // 2개 이상 접해서 녹아야 한다면
    {
        map[r][c] = 0;                  // 처리해주고 치즈 하나 녹았다고 처리
        count--;
    }
}

int main(void)
{
    cin >> N >> M;
    for(int r = 1 ; r <= N ; r++)
    {
        for(int c = 1 ; c <= M ; c++)
        {
            cin >> map[r][c];
            if(map[r][c] == 1)
            {
                count++;
            }
        }
    }

    while(count > 0)                    // 치즈가 다 녹을 때 까지
    {
        reset();                        // 매 시간마다 외부공기 확인해주고
        for(int r = 2 ; r < N ; r++)    // 녹아야 할 치즈는 녹여줌
            for(int c = 2 ; c < M ; c++)
                if(map[r][c] == 1) check(r, c);
        }
        hour++;
    }

    cout << hour << endl;
}