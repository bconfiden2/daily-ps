#include <iostream>
#include <queue>

using namespace std;

unsigned long long a, b, cur;                   // 자료형에 따른 오버플로우 주의할 것
int count = 1;

int main(void)
{
    cin >> a >> b;

    queue<unsigned long long> q;
    q.push(a);

    while(q.size())
    {
        int size = q.size();
        for(int i = 0 ; i < size ; i++)         // 연산의 최솟값 별로 bfs 탐색
        {
            cur = q.front();
            q.pop();
            if(cur > b) continue;               // 가능한 연산이 모두 단조 증가이므로, b 보다 큰 수 중에서는 b로 갈 수 없다
            if(cur == b)
            {
                cout << count << endl;          // b에 도착했을 경우, 연산의 최솟값을 출력해주고 프로그램 종료
                return 0;
            }
            q.push(cur * 2);                    // 2를 곱한 수
            q.push(cur * 10 + 1);               // 오른쪽에 1을 추가한 수
        }
        count++;
    }

    cout << -1 << endl;                         // B로 정상적으로 도착하지 못했을 경우
}