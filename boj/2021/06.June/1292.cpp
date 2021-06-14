#include <iostream>

using namespace std;

int A, B, cnt, idx=1, leftv, value, cur=1;

int main(void)
{
    cin >> A >> B;
    while(true)
    {
        if(idx == A) leftv = value;
        value += cur;
        if(idx == B) break;
        idx++, cnt++;
        if(cnt == cur) cnt = 0, cur++;
    }
    cout << value-leftv << endl;
}