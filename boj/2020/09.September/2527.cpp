#include <iostream>

using namespace std;

int main(void)
{
    for(int k = 0 ; k < 4 ; k++)
    {
        int lx1, ly1, rx1, ry1, lx2, ly2, rx2, ry2;
        cin >> lx1 >> ly1 >> rx1 >> ry1 >> lx2 >> ly2 >> rx2 >> ry2;
        if(ry1 < ly2 || ry2 < ly1 || rx1 < lx2 || rx2 < lx1)
            cout << 'd' << endl;
        else if((lx1==rx2&&ly1==ry2) || (rx1==lx2&&ry1==ly2) || (rx1==lx2&&ly1==ry2) || (rx2==lx1&&ly2==ry1))
            cout << 'c' << endl;
        else if(lx1 == rx2 || rx1 == lx2 || ly1 == ry2 || ry1 == ly2)
            cout << 'b' << endl;
        else
            cout << 'a' << endl;
    }
}