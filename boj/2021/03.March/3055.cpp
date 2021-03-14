#include <iostream>
#include <queue>

using namespace std;

int R, C, count;
bool map[50][50];               // 입력받을 지도
bool visit[50][50];             // 수달의 방문여부
char item;
int dir[4] = {1, -1, 0, 0};     // 4방향
pair<int, int> D;               // 목적지 위치

int main(void)
{
    queue<pair<int,int>> q;             // 수달의 가능 위치들
    queue<pair<int,int>> waterfall;     // 물의 위치(새롭게 퍼진 물에 대해서만)
 
    cin >> R >> C;
    for(int r = 0 ; r < R ; r++)
    {
        for(int c = 0 ; c < C ; c++)
        {
            visit[r][c] = false;        // 수달 방문 배열 전부 false 로 초기화
            cin >> item;
            if(item == '.') map[r][c] = true;
            else
            {
                map[r][c] = false;
                if(item == 'S')         // 수달의 경우
                {
                    map[r][c] = true;
                    visit[r][c] = true; // 해당 위치 방문처리해주고
                    q.push({r, c});     // q 의 시작점으로 넣음
                }
                else if(item == 'D') D = {r, c};
                else if(item == '*') waterfall.push({r, c});    // 물들도 시작점들로 전부 넣어줌
            }
        }
    }

    while(q.size())                                     // 수달이 이동 불가능해질때 까지
    {
        int wsize = waterfall.size();                   // 물 흐르는 것 미리 적용
        for(int wi = 0 ; wi < wsize ; wi++)             // 새롭게 퍼질 모든 물들에 대해서
        {
            pair<int,int> water = waterfall.front();
            waterfall.pop();
            for(int i = 0 ; i < 4 ; i++)                // 각 4방향으로, 퍼질 수 있다면 퍼뜨림
            {
                int nr = water.first + dir[3-i];
                int nc = water.second + dir[i];
                if(nr >= 0 && nr < R && nc >= 0 && nc < C)
                {
                    if(map[nr][nc])
                    {
                        waterfall.push({nr, nc});
                        map[nr][nc] = false;
                    }
                }
            }
        }
        
        int qsize = q.size();
        for(int qi = 0 ; qi < qsize ; qi++)             // 수달의 모든 현재 위치를 검사
        {
            pair<int,int> curS = q.front();
            q.pop();
            if(curS.first == D.first && curS.second == D.second)    // 현재 위치가 목적지면 종료
            {
                cout << count << endl;
                return 0;
            }
            for(int i = 0 ; i < 4 ; i++)                // 현재 위치에서 4방향을 검사
            {
                int nr = curS.first + dir[3-i];
                int nc = curS.second + dir[i];
                if(nr >= 0 && nr < R && nc >= 0 && nc < C)
                {
                    if((nr == D.first && nc == D.second) || map[nr][nc])    // 다음위치가 목적지이거나 이동가능한 곳일 경우
                    {
                        if(!visit[nr][nc])              // 방문하지 않았던 곳이라면
                        {
                            visit[nr][nc] = true;       // 방문처리해주고
                            q.push({nr, nc});           // 수달의 다음 회차 위치에 넣어줌
                        }
                    }
                }
            }
        }
        count++;
    }

    cout << "KAKTUS" << endl;
}