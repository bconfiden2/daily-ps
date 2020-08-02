#include <iostream>

using namespace std;

int a, b, c, d, e, f;
int x, y;

int main(void)
{
    cin >> a >> b >> c >> d >> e >> f;
    
    x = (e*c - b*f) / (a*e - b*d);          // 역행렬을 곱해서 답을 구함
    y = (a*f - d*c) / (a*e - b*d);
    cout << x << " " << y << '\n';
}