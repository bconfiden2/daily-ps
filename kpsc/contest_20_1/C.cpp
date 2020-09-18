#include <iostream>

using namespace std;

int tc;
int a, b, c, n;

int main(void)
{
    cin >> tc;

    while(tc--)
    {
        cin >> a >> b >> c >> n;
        int maxi = max(max(a, b), c);
        if(a + b + c + n >= 3 * maxi) 
        {
            if( (n - (3*maxi - (a+b+c))) % 3 == 0 )
            {
                cout << "YES" << '\n';
                continue;
            }
        }
        cout << "NO" << '\n';
    }
}