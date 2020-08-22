#include <iostream>

using namespace std;

int n, m, k;
int arr1[100][100];
int arr2[100][100];

int main(void)
{
    cin >> n >> m;
    for(int r = 0 ; r < n ; r++)
    {
        for(int c = 0 ; c < m ; c++)
        {
            cin >> arr1[r][c];
        }
    }

    cin >> m >> k;
    for(int r = 0 ; r < m ; r++)
    {
        for(int c = 0 ; c < k ; c++)
        {
            cin >> arr2[r][c];
        }
    }

    for(int r = 0 ; r < n ; r++)
    {
        for(int c = 0 ; c < k ; c++)
        {
            int data = 0;
            for(int i = 0 ; i < m ; i++)
            {
                data += arr1[r][i] * arr2[i][c];
            }
            cout << data << " ";
        }
        cout << '\n';
    }
}
