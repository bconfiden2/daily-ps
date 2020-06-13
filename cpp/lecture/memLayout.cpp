#include <iostream>
using namespace std;

static int dataS = 0;

int dataA;
int dataB = 1;

int main(void)
{
    int a = 4;
    int b = 6;
    int c = 7;

    int* pa = new int(5);
    int* pb = new int(6);

    cout << &dataS << endl;
    cout << &dataA << endl;
    cout << &dataB << endl;

    cout << &c << endl;
    cout << &b << endl;
    cout << &a << endl;

    cout << pa << endl;
    cout << pb << endl;
}