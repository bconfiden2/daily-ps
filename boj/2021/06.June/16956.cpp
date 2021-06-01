#include <iostream>

using namespace std;

int R, C;
int dir[4] = {1, -1, 0, 0};
char map[500][500];

bool check(int r, int c)
{
    for(int i = 0 ; i < 4 ; i++)        // 4방향에 양과 근접해있는지 확인
    {
        int nextR = r + dir[i];
        int nextC = c + dir[3-i];
        if(nextR < 0 || nextR >= R || nextC < 0 || nextC >= C) continue;
        if(map[nextR][nextC] == 'S') return true;
    }
    return false;
}

int main(void)
{
    cin >> R >> C;
    for(int r = 0 ; r < R ; r++)
    {
        for(int c = 0 ; c < C ; c++)
        {
            cin >> map[r][c];
        }
    }

    for(int r = 0 ; r < R ; r++)
    {
        for(int c = 0 ; c < C ; c++)
        {
            if(map[r][c] == '.')        // 빈 공간은 전부 울타리로 채워주고
            {
                map[r][c] = 'D';
            }
            else if(map[r][c] == 'W')
            {
                if(check(r, c))         // 늑대 바로 옆에 양이 있을 경우는 울타리로 커버 불가능
                {
                    cout << 0 << endl;
                    return 0;
                }
            }
        }
    }

    cout << 1 << endl;
    for(int r = 0 ; r < R ; r++)
    {
        for(int c = 0 ; c < C ; c++)
        {
            cout << map[r][c];
        }
        cout << endl;
    }
}
