#include <iostream>
#include <queue>

using namespace std;

int n, k;
int visited[100001];
priority_queue<pair<int,int>> q;

void check(int n, int next)
{
    if((0 <= n && n <= 100000) && visited[n] > next)    // 인덱스 검사, 최단 거리 여부 검사 후
    {
        visited[n] = next;                      // 최단 거리 갱신하고
        q.push(pair<int,int>(-next, n));        // 큐에 해당 노드 푸시
    }
}

int main(void)
{
    for(int i = 0 ; i <= 100000 ; i++)          // 초깃값은 이상값으로 설정
        visited[i] = 100001;

    cin >> n >> k;
    q.push(pair<int,int>(0, n));
    visited[n] = 0;                             // 시작 노드 설정
    
    while(q.size())
    {
        int pos = q.top().second;
        int time = -q.top().first;
        q.pop();

        check(pos - 1, time + 1);               // 각 3 군데를 체크
        check(pos + 1, time + 1);
        check(pos * 2, time);
    }

    cout << visited[k] << endl;
}