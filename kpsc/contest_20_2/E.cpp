#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int answer;

int main(void)
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m;
    vector<vector<int>> nodes(n + 1);
    for(int i = 0, a, b ; i < m ; i++)
    {
        cin >> a >> b;
        nodes[a].push_back(b);
        nodes[b].push_back(a);
    }

    vector<bool> visited(n + 1, false);

    for(int i = 1 ; i <= n ; i++)
    {
        if(visited[i] == false)
        {
            queue<int> q;
            q.push(i);
            int counter = 1;
            visited[i] = true;
            while(q.size())
            {
                int cur = q.front();
                q.pop();
                for(int f = 0 ; f < nodes[cur].size() ; f++)
                {
                    int friends = nodes[cur][f];
                    if(visited[friends] == false)
                    {
                        visited[friends] = true;
                        q.push(friends);
                        counter++;
                    }
                }
            }

            answer += counter / 2 + 1;
        }
    }
    cout << answer << endl;
}