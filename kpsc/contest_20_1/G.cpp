#include <iostream>

using namespace std;

int t;

int main(void)
{
    cin >> t;
    while(t--)
    {
        int ldx = 1, rdx = 100;
        int n, k, answer;
        string r;
        bool changed = true;
        cin >> n;
        for(int i = 0 ; i < n ; i++)
        {
            cin >> k >> r;
            if(r == "UP")        ldx = k + 1;
            else if(r == "DOWN") rdx = k - 1;
            else                 answer = k;
        }
        if(ldx <= answer && answer <= rdx) changed = false; 
        cout << (changed ? "YES" : "NO") << '\n';
    }
}