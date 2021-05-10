#include <iostream>

using namespace std;

int N, jm, hs;
int round = 1;

int main(void)
{
    cin >> N >> jm >> hs;

    while((jm+1)/2 != (hs+1)/2)
    {
        jm = (jm + 1) / 2;
        hs = (hs + 1) / 2;
        round++;
    }

    cout << round << endl;
}