#include <iostream>

using namespace std;

int n, m;
char data[11][11];

int main(void)
{
    cin >> n >> m;

    for(int r = 0 ; r < n ; r++)
    {
        for(int c = 0 ; c < m; c++)
        {
            cin >> data[r][c];
        }
    }
    for(int r = 0 ; r < n ; r++)
    {
        for(int c = m - 1 ; c >= 0 ; c--)
        {
            cout << data[r][c];
        }
        cout << '\n';
    }
}