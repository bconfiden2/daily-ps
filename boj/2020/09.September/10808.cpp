#include <iostream>

using namespace std;

string line;
int answer[26];

int main(void)
{
    cin >> line;
    for(int i = 0 ; i < line.size() ; i++)
    {
        answer[line[i]-97]++;
    }
    for(int i = 0 ; i < 26 ; i++)
    {
        cout << answer[i] << " ";
    }
    cout << endl;
}