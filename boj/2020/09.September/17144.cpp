#include <iostream>

using namespace std;

int R, C, T, answer;
int room[51][51];           // 미세먼지 저장
int temp[51][51];           // 미세먼지 임시처리용
int cdir[51][51];           // 공기청정기 순환 방향
int dir[4] = {-1, 1, 0, 0}; // 4 방향
int pos;                    // 공기청정기의 위치(아래칸)

bool check(int r, int c)                            // 미세먼지가 확산될 수 있는지 확인하는 함수
{
    if(1 <= r && r <= R && 1 <= c && c <= C)        // 인덱스 정상적이고
    {
        if(room[r][c] != -1) return true;           // 공기청정기가 아닐 경우에만 true 반환
    }
    return false;
}

int main()
{
    cin >> R >> C >> T;
    for(int r = 1 ; r <= R ; r++)
        for(int c = 1 ; c <= C ; c++)
        {
            cin >> room[r][c];
            cdir[r][c] = -1;
            if(room[r][c] == -1) pos = r;           // 공기청정기 위치 pos
        }
    for(int i = 1 ; i <= C ; i++)
    {
        if(i != 1)
        {
            cdir[1][i] = 3;                         // 각 위치별로 공기청정기의 순환방향 저장
            cdir[R][i] = 3;
        }
        if(i != C)
        {
            cdir[pos-1][i] = 2;
            cdir[pos][i] = 2;
        }
    }
    for(int i = 1 ; i <= R ; i++)
    {
        if(i < pos)
        {
            if(i != pos - 1) cdir[i][1] = 1;
            if(i != 1) cdir[i][C] = 0;
        }
        else
        {
            if(i != R) cdir[i][C] = 1;
            if(i != pos) cdir[i][1] = 0;
        }
    }

    for(int t = 0 ; t < T ; t++)
    {
        for(int r = 1 ; r <= R ; r++)               // 미세먼지 확산 계산
            for(int c = 1 ; c <= C ; c++)
            {
                int amount = room[r][c] / 5;        // 확산량
                int count = 0;                      // 확산되는 방향 수
                for(int i = 0 ; i < 4 ; i++)        // 4 방향 확인해서 확산 처리
                {
                    if(check(r + dir[i], c + dir[3-i]))
                    {
                        count++;
                        temp[r + dir[i]][c + dir[3-i]] += amount;
                    }
                }
                room[r][c] -= (amount * count);       // (r,c) 에 남은 미세먼지 양
            }
        for(int r = 1 ; r <= R ; r++)               // 실제 확산 처리
            for(int c = 1 ; c <= C ; c++)
                temp[r][c] += room[r][c];           // temp 에 있던 확산량을 각 위치에 더해주고

        for(int r = 1 ; r <= R ; r++)
        {
            for(int c = 1 ; c <= C ; c++)
            {
                if(cdir[r][c] == -1)
                {
                    room[r][c] = temp[r][c];
                }
                else
                {
                    int d = cdir[r][c];
                    room[r + dir[d]][c + dir[3-d]] = temp[r][c];    // 공기 순환 처리
                }
                temp[r][c] = 0;
            }
        }
        room[pos][1] = -1;
        room[pos-1][1] = -1;                        // 공기청정기 위치 초기화
        room[pos][2] = 0;                           // 공기청정기를 거친 공기들은 미세먼지 0
        room[pos-1][2] = 0;
    }

    for(int r = 1 ; r <= R ; r++)                   // 남은 미세먼지의 총합을 구함
        for(int c = 1 ; c <= C ; c++)
            answer += room[r][c];
    cout << answer + 2 << endl;                     // 공기청정기 고려해서 +2
}