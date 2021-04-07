#include <iostream>

using namespace std;

bool batch[5][5];               // 입력되는 자리배치 배열
bool visited[5][5];             // 선택된 7명에 대한 정보
bool fordfs[5][5];              // dfs 돌 때 방문 여부 확인 배열
int dir[4] = {1, -1, 0, 0};
int connected;                  // dfs 돌 때 7명 다 연결되어있는지 확인하는 값
int count = 0;
char temp;

void dfs(int r, int c)
{
    fordfs[r][c] = true;                        // 방문처리해 준 뒤
    connected++;                                // 연결된 학생 수 조절
    for(int i = 0 ; i < 4 ; i++)                // 4방향에 대해서
    {
        int nextR = r + dir[i];
        int nextC = c + dir[3-i];
        if(nextR < 0 || nextR >= 5 || nextC < 0 || nextC >= 5) continue;
        if(!visited[nextR][nextC]) continue;    // 뽑힌 7명이 아니면 스킵
        if(fordfs[nextR][nextC]) continue;      // 이전에 방문했던 노드면 스킵
        dfs(nextR, nextC);                      // 끝까지 탐색
    }
}

void select(int idx, int cnt, int S)            // 재귀적으로 자리에 상관 없이 7명을 뽑는 함수
{
    if(cnt == 7)                                // 7명을 다 뽑은 상태이고
    {
        if(S >= 4)                              // 만약 이다솜파가 4명 이상이라면, 그 7명의 자리가 연결되어있는지 확인해봄
        {
            for(int i = 0 ; i < 25 ; i++) fordfs[i/5][i%5] = false;
            connected = 0;

            for(int i = 0 ; i < 25 ; i++)       // 아무 자리에서 dfs를 한번 돌렸을 때 7명 이하가 나오면 연결되지 않았다는 뜻
            {
                if(visited[i/5][i%5])           // 처음 나온 자리에서 dfs 돌리고
                {
                    dfs(i/5, i%5);
                    count += (connected == 7);  // 7명이 아니면 스킵
                    break;   
                }
            }
        }
        return;
    }

    for(int i = idx + 1 ; i < 25 ; i++)         // 7명 뽑을때까지 한명씩 재귀적으로 뽑음
    {
        if(visited[i/5][i%5]) continue;         // 이미 뽑은 사람을 제외하고 뽑아줌
        visited[i/5][i%5] = true;
        select(i, cnt + 1, S + batch[i/5][i%5]);
        visited[i/5][i%5] = false;
    }
}

int main(void)
{
    for(int i = 0 ; i < 5 ; i++)
    {
        for(int j = 0 ; j < 5 ; j++)
        {
            cin >> temp;
            batch[i][j] = (temp=='S' ? true : false);
        }
    }
    
    select(-1, 0, 0);           // 조합을 뽑아준다

    cout << count << endl;
}