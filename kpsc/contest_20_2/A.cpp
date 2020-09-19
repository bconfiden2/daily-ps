#include <iostream>

using namespace std;

int tc;
string n;

int main(void)
{
    cin >> tc;
    while(tc--)
    {
        cin >> n;
        int digit = n.size() - 1;
        for(int i = 0 ; i < n.size() ; i++, digit--)
        {
            cout << n[i];
            if(n[i] != '0')
            {
                for(int j = 0 ; j < digit ; j++)
                {
                    cout << 0;
                }
            }
            cout << " ";
        }
        cout << '\n';
    }
}