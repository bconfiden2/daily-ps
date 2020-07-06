#include <iostream>
#include <queue>
using namespace std;

int n, k, answer;
bool visited[100001];

int main(void)
{
    cin >> n >> k;
    queue<pair<int,int>> q;                             // pair<위치, 이동횟수>
    q.push(pair<int,int>(n,0));                         // 처음 위치인 n 과, 이동 횟수 0번을 넣고 시작
    while(true)
    {
        pair<int, int>& temp = q.front();
        if(temp.first < 0 || temp.second > 100000)      // 방문 여부 체크하는데 인덱스 범위 검사 먼저 해주고
        {
            q.pop();
            continue;
        }
        if(visited[temp.first])                         // 만약에 앞에서 방문했었던 위치라면
        {                                               // 그 뒤에서 검사하는 것 역시 의미가 없기 때문에
            q.pop();                                    // 검사하지 않고 넘어간다
            continue;
        }
        if(temp.first == k)                             // 만약 동생의 위치에 도달했을 경우
        {
            answer = temp.second;                       // 해당 계층이 최단 거리임을 나타냄
            break;
        }
        visited[temp.first] = true;                     // 방문한 노드도 아니고, 동생 위치도 아닐 경우
        q.push(pair<int,int>(temp.first + 1, temp.second + 1)); // 갈 수 있는 위치 3군데 다 넣어줌
        q.push(pair<int,int>(temp.first - 1, temp.second + 1));
        q.push(pair<int,int>(temp.first * 2, temp.second + 1));
        q.pop();
    }

    cout << answer << '\n';
}