#include <iostream>

using namespace std;

int c, k, p;

int main(void)
{
    cin >> c >> k >> p;
    int answer = 0;
    for(int i = 1 ; i <= c ; i++)
    {
        answer += k * i + p * i* i;
    }
    cout << answer << endl;
}