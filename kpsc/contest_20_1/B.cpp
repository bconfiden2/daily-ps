#include <iostream>
#include <vector>
#include <queue>

#define INF 10e8

using namespace std;

int n, m, k;
int startp, endp;
int answer = -1, tans;

int main(void)
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m;
    vector<vector<int>> stops(n + 1);
    vector<vector<int>> trans(m + 1);
    for(int tr = 1 ; tr <= m ; tr++)
    {
        cin >> k;
        for(int i = 0, st ; i < k ; i++)
        {
            cin >> st;
            trans[tr].push_back(st);
            stops[st].push_back(tr);
        }
    }
    cin >> startp >> endp;
    
    vector<int> mini(n + 1, INF);

    priority_queue<pair<int,int>> q;
    q.push({0, startp});
    mini[startp] = 0;
    while(q.size())
    {
        int tfCount = -q.top().first;
        int curPos = q.top().second;
        q.pop();
        for(int i = 0 ; i < stops[curPos].size() ; i++)
        {
            int tr = stops[curPos][i];
            for(int j = 0 ; j < trans[tr].size() ; j++)
            {
                int nextPos = trans[tr][j];
                if(tfCount + 1 < mini[nextPos])
                {
                    cout << curPos << " -> " << nextPos << endl;
                    mini[nextPos] = tfCount + 1;
                    q.push({-tfCount - 1, nextPos});
                }
            }
        }
    }

    cout << (mini[endp] == INF ? -1 : mini[endp] - 1) << '\n';
}