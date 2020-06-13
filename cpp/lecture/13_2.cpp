#include <iostream>
using namespace std;

int f2(int a, int b = 0, int* sum = NULL, int* diff = NULL)
{
    *sum = a + b;
    *diff = a - b;
    return *sum;
}

int f3(int* arrays, int size)
{
    cout << sizeof(arrays) << endl;
    cout << arrays << endl;
    int sum = 0;
    for(int i = 0 ; i < size ; i++)
    {
        sum += arrays[i];
    }
    return sum;
}

int main(void)
{
    int* ptr = new int(3);

    cout << ptr << endl;
    if(ptr)
    {
        cout << "!!!!!" << endl;
    }

    int i = 1, j = 2, sum = 0, diff = 0;

    f2(i, j, &sum, &diff);

    cout << sum << endl;
    cout << diff << endl;

    int a[5] = {1,2,3,4,5};
    cout << sizeof(a) << endl;
    cout << a << endl;

    sum = f3(a, 5);

    cout << sum << endl;
}