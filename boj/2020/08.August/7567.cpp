#include <iostream>
#include <string>

using namespace std;

string temp;
bool state;
int answer;

int main(void)
{
    cin >> temp;
    if(temp[0] == '(') state = true;
    else state = false;
    answer = 10;
    
    for(int i = 1 ; i < temp.size() ; i++)
    {
        if(temp[i] == '(')
        {
            if(state == true) answer += 5;
            else answer += 10;
            state = true;
        }
        else
        {
            if(state == false) answer += 5;
            else answer += 10;
            state = false;
        }
    }
    cout << answer << endl;
}