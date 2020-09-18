#include <iostream>

using namespace std;

int cup_n, mix_n, answer;

int main(void)
{
    cin >> cup_n >> mix_n >> answer;
    for(int i = 0 ; i < mix_n ; i++)
    {
        int a, b;
        cin >> a >> b;
        if(a == answer) answer = b;
        else if(b == answer) answer = a;
    }
    cout << answer << '\n';
}