#include <iostream>
#include <queue>

using namespace std;

int abs(int n) { return n >= 0 ? n : -n; }          // 절댓값 반환 함수

struct cmp
{
    bool operator()(const pair<int,int>& a, const pair<int,int>& b)
    {
        if(a.first == b.first)                      // 절댓값이 같을 경우에는
        {                                           // 원값을 기준으로 오름차순 정렬
            return a.second > b.second;
        }
        else return a.first > b.first;              // 그 외에는 절댓값 기준 정렬
    }
};

int main(void)
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq; // 우선순위 큐 선언
    for(int i = 0 , data ; i < n ; i++)
    {
        cin >> data;
        if(data == 0)
        {
            if(pq.empty()) cout << 0 << '\n';
            else
            {
                cout << pq.top().second << '\n';
                pq.pop();
            }
        }
        else
        {
            pq.push(pair<int,int>(abs(data), data));
        }
    }
}