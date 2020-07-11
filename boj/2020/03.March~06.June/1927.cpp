#include <iostream>
#include <queue>
using namespace std;

int main(void)
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0 , data ; i < n ; i++)
    {
        cin >> data;
        if(data == 0)
        {
            if(pq.empty()) cout << 0 << '\n';
            else
            {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        else
        {
            pq.push(data);
        }
    }
}
