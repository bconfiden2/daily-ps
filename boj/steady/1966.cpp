#include <iostream>
#include <deque>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int testCases = 0;
    cin >> testCases;
    for(int tc = 0 ; tc < testCases ; tc++)
    {
        int n, m;
        cin >> n >> m;
        int val = 0;
        deque<int> que;

        // 덱에 다 집어넣어준다
        for(int i = 0 ; i < n ; i++)
        {
          cin >> val;
          que.push_back(val);
        }

        int prior = m; // 내가 목표로 하는 문서의 인덱스
        int printCount = 0; // 몇번째 출력중인지 확인

        // 계속 반복하다가 출력하려는 문서가 prior 이라면 빠져나온다.
        while(1)
        {
          int i = 0;
          // 내 뒤에있는 문서들 완전탐색
          for(i = 0 ; i < que.size() ; i++)
          {
            if(que[i] > que[0]) // 만약 나보다 큰 놈이 있으면
            {
              que.push_back(que[0]); // 맨 뒤로 옮겨주고
              que.pop_front();
              if(prior == 0) prior = que.size() - 1; // 만약 목표문서를 옮긴거라면 인덱스도 맨 뒤로
              else prior--; // 목표문서가 아니라면 앞에서 하나 땡겨졌기 때문에 1 감소

              break;
            }
          }
          // 만약 중간에 빠져나온 거라면 밑을 실행하지 않음
          if(i != que.size()) continue;
          // 내 뒤에 나보다 우선순위 큰 문서가 없을 경우에
          if(prior == 0) // 이번에 뽑을 문서가 내가 목표로 하던 문서라면
          {
            printCount++; // 프린트해주고 빠져나감
            break;
          }
          else // 내가 목표로 하던 문서가 아니라면
          {
            que.pop_front(); // 프린트해주고
            printCount++;
            prior--; // 하나 빠졌으니 목표 인덱스도 1 감소
          }
        }

        cout << printCount << '\n';
    }
}
