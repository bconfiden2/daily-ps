#include <iostream>
#include <queue>
#define pairs pair<int,string>          // 큐에 넣어줄 데이터 형식, <값, 명령어>
using namespace std;

int tc = 0;
int a, b;
char funcs[4] = {'D', 'S', 'L', 'R'};
int answers[10000][4];                  // 각 숫자별로 DSLR 연산 시 나올 결과값 선계산
bool visited[10000];

int ret(int temp, int func)             // DSLR 각 연산
{
    if(func == 0)       temp = (temp * 2) % 10000;                  // D
    else if(func == 1)  temp -= 1;                                  // S
    else if(func == 2)  temp = (temp % 1000) * 10 + (temp / 1000);  // L
    else                temp = (temp / 10) + (temp % 10) * 1000;    // R

    if(temp < 0) temp = 9999;
    return temp;
}

int main(void)
{
    cin >> tc;
    for(int i = 0 ; i < 10000 ; i++)            // 숫자별 DSLR 값들 선계산
    {
        for(int j = 0 ; j < 4 ; j++)
        {
            answers[i][j] = ret(i, j);
        }
    }
    while(tc--)
    {
        for(int i = 0 ; i < 10000 ; i++) visited[i] = false;    // 케이스마다 방문 정보 초기화
        cin >> a >> b;

        queue<pairs> q;
        int cur;
        q.push(pairs(a, ""));                   // 첫 숫자 입력
        visited[a] = true;                      // 첫 숫자 방문 처리
        while(true)
        {
            cur = q.front().first;
            if(cur == b) break;                 // 만약 목표 값에 도달했다면 종료
            for(int i = 0, k ; i < 4 ; i++)     // 그게 아닐 경우 DSLR 해당하는 값들 큐에 푸시
            {
                k = answers[cur][i];
                if(visited[k]) continue;        // 만약 해당 명령어의 값이 이미 처리되었던 값이면 스킵
                visited[k] = true;              // 아닐 경우 방문 처리 해주고
                q.push(pairs(k, q.front().second + funcs[i]));  // 해당 명령어의 값을 푸시해줌
            }
            q.pop();
        }
        cout << q.front().second << '\n';       // 목표 값까지 도달한 명령어 출력
    }
}