#include <iostream>
#include <queue>
#include <algorithm>
#include <set>

using namespace std;

int N, K;
int values[8];
int sorted_values[8];

int main(void)
{
    cin >> N >> K;

    string start = "";
    for(int i = 0 ; i < N ; i++)
    {
        cin >> sorted_values[i];
        start += to_string(sorted_values[i]);       // BFS 시작할 문자열
    }

    sort(sorted_values, sorted_values + N);
    string answer = "";
    for(int i = 0 ; i < N ; i++)
    {
        answer += to_string(sorted_values[i]);      // 목표로 하는(오름차순 순열) 답을 구해 놓음
    }

    queue<pair<string,int>> q;
    q.push({start, 0});
    set<string> visited;
    visited.insert(start);                          // 중복을 검사하기 위해서 8! 개 만큼만 필요하기 때문에 전부 검사 가능

    while(q.size())
    {
        string cur = q.front().first;
        int cur_cnt = q.front().second;
        q.pop();
        if(cur == answer)                           // 정답에 도달했으면 뒤집은 횟수 출력하고 종료
        {
            cout << cur_cnt << endl;
            return 0;
        }
        for(int i = 0 ; i <= N - K ; i++)           // 이번 뒤집기에서 가능한 모든 뒤집기를 검사
        {
            string next = "";
            for(int k = 0 ; k < i ; k++) next += cur[k];
            for(int k = 0 ; k < K ; k++) next += cur[K+i-k-1];
            for(int k = i + K ; k < N ; k++) next += cur[k];
            if(visited.find(next) == visited.end())
            {
                visited.insert(next);
                q.push({next, cur_cnt+1});
            }
        }
    }

    cout << -1 << endl;
}