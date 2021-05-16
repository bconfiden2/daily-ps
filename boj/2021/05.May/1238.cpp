#include <iostream>
#include <memory.h>
#define INF 1000000000

using namespace std;

int N, M, X, answer;
int s, e, t;
int times[1001][1001];

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> X;

    for(int r = 1 ; r <= N ; r++)
    {
        for(int c = 1 ; c <= N ; c++)           // 그래프 초기화
        {
            if(r == c) times[r][c] = 0;         // 자기자신으로 가는 에지는 0
            else times[r][c] = INF;             // 그 외는 최댓값
        }
    }

    for(int i = 0 ; i < M ; i++)
    {
        cin >> s >> e >> t;
        times[s][e] = t;                        // 단방향 연결
    }

    for(int k = 1 ; k <= N ; k++)               // 플로이드 와샬
    {
        for(int r = 1 ; r <= N ; r++)
        {
            for(int c = 1 ; c <= N ; c++)
            {
                if(times[r][k] + times[k][c] < times[r][c])
                    times[r][c] = times[r][k] + times[k][c];
            }
        }
    }

    for(int i = 1 ; i <= N ; i++)               // 각 노드별로 i 에서 X 로 가는 시간과
    {                                           // X 에서 i 로 돌아오는 시간의 합이 가장 큰 값
        if(times[X][i] + times[i][X] > answer)
            answer = times[X][i] + times[i][X];
    }
    cout << answer << endl;
}