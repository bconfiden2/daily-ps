#include <iostream>

#define INF 1000000000

using namespace std;

int n, m, a, b, c;
int answer[101][101];

int main(void)
{
    cin >> n >> m;

    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = 1 ; j <= n ; j++)
        {
            answer[i][j] = (i == j ? 0 : INF);      // 행렬 INF 로 초기화
        }
    }

    for(int i = 0 ; i < m ; i++)
    {
        cin >> a >> b >> c;
        if(answer[a][b] > c) answer[a][b] = c;      // 동일한 노선이 있을 수 있으니 최소 비용 노선으로 저장
    }

    for(int k = 1 ; k <= n ; k++)                   // 플로이드 와샬
    {
        for(int i = 1 ; i <= n ; i++)
        {
            for(int j = 1 ; j <= n ; j++)
            {
                if(answer[i][j] > answer[i][k] + answer[k][j])
                {
                    answer[i][j] = answer[i][k] + answer[k][j];
                }
            }
        }
    }

    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = 1 ; j <= n ; j++)
        {
            cout << (answer[i][j] == INF ? 0 : answer[i][j]) << " ";    // INF 로 남아있는 값은 연결되지 않는다는 것
        }
        cout << endl;
    }
}