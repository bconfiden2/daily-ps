#include <iostream>
#include <queue>

using namespace std;

int N, S, total, temp, answer=100000;

int main(void)
{
    cin >> N >> S;
    queue<int> q;
    for(int i = 0 ; i < N ; i++)        // 수열의 수들을 하나씩 입력받으면서
    {
        cin >> temp;
        q.push(temp);                   // 큐에 넣어주고
        total += temp;                  // 부분합을 업데이트해줌
        while(total >= S)               // 만약 현재 큐의 원소들의 합(부분합)이 
        {
            if(q.size() < answer) answer = q.size();    // 현재 부분합이 최소 길이일 경우 갱신
            total -= q.front();         // 앞의 원소를 제외해줌
            q.pop();                    // 제외한 수열의 부분합이 여전히 S 보다 클 경우 반복
        }
    }
    cout << (answer == 100000 ? 0 : answer) << endl;
}