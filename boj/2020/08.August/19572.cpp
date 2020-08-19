#include <iostream>
#include <cmath>

using namespace std;

int x, y, z;
double a, b, c;

int main(void)
{
    cin >> x >> y >> z;
    a = (x + y - z) / 2.0;
    b = (x - y + z) / 2.0;
    c = (-x + y + z) / 2.0;
    if(a > 0 && b > 0 && c > 0)
    {
        cout << fixed;
        cout.precision(1);
        cout << "1" << endl << a << " " << b << " " << c << endl;
    }
    else cout << "-1" << endl;
}