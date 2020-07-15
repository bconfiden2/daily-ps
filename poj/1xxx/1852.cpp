#include <iostream>
#include <algorithm>
using namespace std;

int t;
int len, n;
int x[1000001];

int main(void)
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> t;
    while(t--)
    {
        int _min = 0, _max = 0;
        cin >> len >> n;
        for(int i = 0 ; i < n ; i++)
        {
            cin >> x[i];
        }
        for(int i = 0 ; i < n ; i++)
        {
            _min = max(_min, min(x[i], len - x[i]));
            _max = max(_max, max(x[i], len - x[i]));
        }

        cout << _min << " " << _max << '\n';
        for(int i = 0 ; i < n ; i++)
        {
            x[i] = 0;
        }
    }
}