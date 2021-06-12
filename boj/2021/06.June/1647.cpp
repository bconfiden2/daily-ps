#include <iostream>
#include <queue>

using namespace std;

int N, M, A, B, C;
int parent[100001];

int find_(int x)
{
    if(parent[x] == 0) return x;
    parent[x] = find_(parent[x]);
    return parent[x];
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;

    for(int i = 0 ; i < M ; i++)
    {
        cin >> A >> B >> C;
        pq.push({C, {A,B}});
    }

    int maxi = 0;
    int total = 0;

    while(pq.size())
    {
        int dist = pq.top().first;
        int x = find_(pq.top().second.first);   // 각 노드의 루트값을 찾아서
        int y = find_(pq.top().second.second);
        pq.pop();
        if(x != y)                              // 다른 집단에 속할(순환이 일어나지 않을) 경우에만
        {
            parent[x] = y;                      // 두 집단 유니온
            total += dist;                      // MST 에 포함시켜줌
            if(dist > maxi) maxi = dist;        // MST 를 둘로 나눌 기준 에지 찾기
        }
    }

    cout << total - maxi << endl;
}