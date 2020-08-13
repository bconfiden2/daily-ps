#include <iostream>
#include <algorithm>

using namespace std;

int n, temp;
bool exist[10000001];

int main(void)
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> temp;
        if(exist[temp]) break;
        exist[temp] = true;
    }
    cout << temp << endl;
}