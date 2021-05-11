#include <iostream>
#include <queue>

using namespace std;

int N, temp, count;
int visited[1000001];

int main(void)
{
    cin >> N;
    queue<pair<int, string>> q;
    q.push({N, ""});

    while(true)
    {
        int sz = q.size();
        for(int s = 0 ; s < sz ; s++)                               // bfs
        {
            int cur = q.front().first;
            string answer = q.front().second;
            q.pop();

            if(cur == 1)                                            // 1 에 도착할 시
            {
                cout << count << endl << answer + "1" << endl;      // 연산 횟수 및 경로 출력 후 종료
                return 0;
            }

            temp = cur-1;
            if(!visited[temp])                                      // 3번 케이스
            {
                visited[temp] = true;
                q.push({temp, answer + to_string(cur) + " "});
            }
            if(cur % 2 == 0)                                        // 2번 케이스
            {
                temp = cur / 2;
                if(!visited[temp])
                {
                    visited[temp] = true;
                    q.push({temp, answer + to_string(cur) + " "});
                }
            }
            if(cur % 3 == 0)                                        // 1번 케이스
            {
                temp = cur / 3;
                if(!visited[temp])
                {
                    visited[temp] = true;
                    q.push({temp, answer + to_string(cur) + " "});
                }
            }
        }
        count++;
    }
}