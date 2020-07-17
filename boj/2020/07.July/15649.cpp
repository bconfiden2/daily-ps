#include <iostream>

using namespace std;

int n, m;
int ans[8];
bool visited[9];

void check(int idx, int size)
{
    if(size == m)
    {
        for(int i = 0 ; i < m ; i++)
        {
            cout << ans[i] << " ";
        }
        cout << '\n';
        return;
    }

    for(int i = 1 ; i <= n ; i++)
    {
        if(visited[i] == false)
        {
            visited[i] = true;
            ans[size] = i;
            check(i, size + 1);
            visited[i] = false;
        }
    }
}

int main(void)
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m;

    check(0, 0);
}