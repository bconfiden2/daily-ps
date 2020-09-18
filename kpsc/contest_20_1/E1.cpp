#include <iostream>
#include <vector>

using namespace std;

int n;
int types[11];
int answer;

int main(void)
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;
    for(int i = 0, temp ; i < n ; i++)
    {
        cin >> temp;
        types[temp]++;

        vector<int> couType;
        for(int j = 1 ; j <= 10 ; j++)
        {
            if(types[j]) couType.push_back(types[j]);
        }
        bool able = true;
        int summ = 0;
        for(int j = 0 ; j < couType.size() ; j++)
        {
            summ += couType[j];
        }
        
        if(able) if(summ > answer) answer = summ;
    }
    cout << answer << '\n';
}