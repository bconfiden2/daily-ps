#include <iostream>
#include <cstring>

using namespace std;

int main(void)
{
    char str1[] = "adsdfas";
    char str2[6];

    cout << (void*)str1 << endl;
    cout << (void*)str2 << endl;
    cout << str1 << endl;
    cout << str2 << endl;

    strcpy(str2, "abcdefg");

    cout << (void*)str1 << endl;
    cout << (void*)str2 << endl;
    cout << str1 << endl;
    cout << str2 << endl;
    cout << sizeof(str1) << endl;
    cout << sizeof(str2) << endl;
    cout << str2[9] << endl;
}