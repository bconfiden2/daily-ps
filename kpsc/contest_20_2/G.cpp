#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int n, m;
vector<int> v;
map<int,int> mapp;

int main(void)
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m;
    for(int i = 0, temp ; i < n ; i++)
    {
        cin >> temp;
        v.push_back(temp);
    }

    int sz = n;
    int insertion = 0;
    vector<int> out;
    for(int i = 0, t, x ; i < m ; i++)
    {
        cin >> t >> x;
        if(t)
        {
            if(x <= sz)
            {
                sz--;
                x -= insertion;
                out.push_back(x);
                mapp[x] += 1;
            }
        }
        else
        {
            insertion++;
            sz++;
            v.push_back(x);
        }
    }
    sort(v.begin(), v.end());
    sort(out.begin(), out.end());

    for(int i = 1 ; i <= 6 ; i++)
    {
        cout << mapp[i] << " ";
    }
    cout << endl;
    for(int i = 0 ; i < out.size() ; i++)
    {
        v[out[i]+(mapp[out[i]])-1] = -1;
        cout << out[i] << " " << (mapp[out[i]]) << endl;
        mapp[out[i]]--;
        for(int j = 0 ; j < v.size() ; j++)
        {
            cout << v[j] << " ";
        }
        cout << endl;
        for(int j = 1 ; j <= 6 ; j++)
        {
            cout << mapp[j] << " ";
        }
        cout << endl;
    }
    for(int i = 0 ; i < v.size() ; i++)
    {
        if(v[i] != -1) cout << v[i] << " ";
    }
    if(sz <= 0) cout << -1;
    cout << endl;

    cout << "sz : " << sz << endl;

}