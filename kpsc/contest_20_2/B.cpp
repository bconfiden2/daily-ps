#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, s, e;
vector<int> zidx;
vector<pair<int,int>> data;
int answer = 0;

int main(void)
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> s >> e;
        zidx.push_back(s);
        zidx.push_back(e);
        data.push_back({s, e});
    }
    sort(zidx.begin(), zidx.end());
    zidx.erase(unique(zidx.begin(), zidx.end()), zidx.end());

    vector<int> people(zidx.size() + 1, 0);
    for(int i = 0 ; i < data.size() ; i++)
    {
        int lidx = lower_bound(zidx.begin(), zidx.end(), data[i].first) - zidx.begin();
        int ridx = lower_bound(zidx.begin(), zidx.end(), data[i].second) - zidx.begin();
        for(int k = lidx ; k <= ridx ; k++)
        {
            people[k]++;
        }
    }
    for(int i = 0 ; i < people.size() ; i++)
    {
        if(people[i] > answer) answer = people[i];
    }
    cout << answer << endl;
}