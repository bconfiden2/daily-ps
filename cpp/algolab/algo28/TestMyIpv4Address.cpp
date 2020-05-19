#include <iostream>
#include "MyIpv4Address.h"
using namespace std;
int main()
{
    int numTestCases;
    cin >> numTestCases;

    for (int i=0; i<numTestCases; i++)
    {
        unsigned int num;
        char add[16];
        int type;

        //cout << 2078961630 % 256 << " " << 2078961630 % (256*256) / 256 << " " << 2078961630 % (256*256*256) / (256*256) << 2078961630 % (256*256*256*256) / (256*256*256);

        cin >> type;

        if (type == 1)
        {
            cin >> add;
            MyIpv4Address ipv4add(add);
            ipv4add.printNumber();
        }
        else if (type == 2)
        {
            cin >> num;
            MyIpv4Address ipv4add(num);
            ipv4add.printAddress();
        }
    }
    return 0;
}