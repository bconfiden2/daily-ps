#include <iostream>

using namespace std;

int n, m;
int answer[7];

void check(int size)
{
    if(size == m)
    {
        for(int i = 0 ; i < m ; i++)
        {
            cout << answer[i] << " ";
        }
        cout << '\n';
        return;
    }
    
    for(int i = 1 ; i <= n ; i++)
    {
        answer[size] = i;
        check(size + 1);
    }
}

int main(void)
{
    cin >> n >> m;
    check(0);
}