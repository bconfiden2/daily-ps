#include <cstdio>
#include <algorithm>

using namespace std;

int N, M;
int value[8];
int digit[8];

void pick(int cur)
{
    if(cur == M)                            // 자릿수 전부 다 골랐으면 출력
    {
        for(int i = 0 ; i < M ; i++)
        {
            printf("%d ", digit[i]);
        }
        printf("\n");
        return;
    }

    bool visited[10001] = {false,};         // 이번 자릿수의 중복 방지 배열
    for(int i = 0 ; i < N ; i++)            // 중복이 가능하므로 모든 가능한 값들을 탐색
    {
        if(visited[value[i]]) continue;     // 이전에 이미 검사됐던 값이면 스킵
        visited[value[i]] = true;
        digit[cur] = value[i];              // 현재 자릿수에 값을 넣어주고
        pick(cur + 1);                      // 다음 자릿수 재귀적으로 고름
    }
}

int main(void)
{
    scanf("%d %d", &N, &M);
    for(int i = 0 ; i < N ; i++)
    {
        scanf("%d", &value[i]);
    }
    sort(value, value+N);                   // 사전 순 출력을 위한 값 정렬

    pick(0);
}