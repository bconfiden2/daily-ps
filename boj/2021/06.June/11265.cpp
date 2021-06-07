#include <iostream>

using namespace std;

int N, M, A, B, C;
int graph[501][501];

int main(void)
{
    cin >> N >> M;
    for(int r = 1 ; r <= N ; r++)
    {
        for(int c = 1 ; c <= N ; c++)
        {
            cin >> graph[r][c];
        }
    }

    for(int k = 1 ; k <= N ; k++)
    {
        for(int r = 1 ; r <= N ; r++)
        {
            for(int c = 1 ; c <= N ; c++)
            {
                if(graph[r][k] + graph[k][c] < graph[r][c])
                {
                    graph[r][c] = graph[r][k] + graph[k][c];
                }
            }
        }
    }

    for(int i = 0 ; i < M ; i++)
    {
        cin >> A >> B >> C;
        if(graph[A][B] <= C)
        {
            cout << "Enjoy other party\n";
        }
        else
        {
            cout << "Stay here\n";
        }
    }
}