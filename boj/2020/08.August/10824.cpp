#include <iostream>

#define ull unsigned long long

using namespace std;

ull a, b, c, d;

int main(void)
{
    cin >> a >> b >> c >> d;
    int digit = 1;
    while(b / digit)
    {
        digit *= 10;
    }
    a *= digit;
    digit = 1;
    while(d / digit)
    {
        digit *= 10;
    }
    c *= digit;
    cout << a + b + c + d << endl;
}