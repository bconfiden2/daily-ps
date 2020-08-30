#include <iostream>

using namespace std;

int t;
int answer, temp;
int data[101];

int main(void)
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> t;

    for(int i = 0 ; i < t ; i++)
    {
        cin >> temp;
        for(int d = 0 ; d <= 100 ; d++)
        {
            data[d] = 0;
        }
        answer = 0;
        for(int d = 0 ; d < 1000 ; d++)
        {
            cin >> temp;
            data[temp]++;
        }
        for(int d = 0 ; d <= 100 ; d++)
        {
            if(data[d] >= data[answer]) answer = d;
        }
        cout << "#" << i + 1 << " " << answer << '\n';
    }
}