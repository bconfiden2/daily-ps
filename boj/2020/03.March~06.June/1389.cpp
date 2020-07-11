#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;

int main(void)
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m;
    vector<vector<int>> v(n + 1);                                   // 서로 간의 연결에 대한 정보
    vector<vector<bool>> visited;                                   // 각각 연결이 완료됐는지 여부에 대한 2차원 벡터
    for(int i = 0 ; i <= n ; i++)
    {
        vector<bool> temp(n + 1, false);                            // visited 벡터 초기화
        visited.push_back(temp);
    }
    for(int i = 0, a, b ; i < m ; i++)
    {
        cin >> a >> b;                                              // 노드들 연결
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int ans = 0, min = 6 * n;                                       // ans = 최솟값인 사람의 번호, min = 최솟값
    for(int i = 1 ; i <= n ; i++)                                   // 1 ~ n 까지 각 사람들마다의 케빈값을 구할 건데,
    {
        int temp = 0;                                               // temp 는 이번 사람의 케빈값이 들어갈 변수
        vector<bool>& thisVisit = visited[i];                       // visited 보기 편하게 이번 사람 것만 떼옴
        queue<pair<int,int>> q;                                     // bfs 를 위한 큐를 하나 만들고
        q.push(pair<int,int>(i,0));                                 // 해당 사람을 넣고 bfs 시작 (너비 0으로 시작해서 1씩 증가)
        while(true)
        {
            pair<int,int> target = q.front();                       
            if(thisVisit[target.first] || (target.first < 1 || target.first > n))       // 만약 연결이 되었던 사람이라면
            {
                q.pop();                                                                // 스킵
                continue;
            }                                           
            thisVisit[target.first] = true;                          // 연결 안됐던 사람일 경우 연결됨을 표시해주고
            temp += target.second;                                   // 이번 연결에 해당하는 너비값을 케빈값에 더해줌
            for(int j = 0 ; j < v[target.first].size() ; j++)        // 그리고 자기에게 연결된 다른 사람들을 너비값을 더해서 쭉 연결해줌
            {
                q.push(pair<int,int>(v[target.first][j], target.second + 1));
            }
            q.pop();
            int idx;
            for(idx = 1 ; idx <= n ; idx++)                          // n 명이 전부 연결이 되어야지 종료함
            {
                if(thisVisit[idx] == false) break;
            }
            if(idx == n + 1) break;
        }
        if(temp < min)                                                  // 최종적으로 이번 사람의 케빈값이 최솟값보다 작으면
        {                                                                
            min = temp;                                                 // 바꿔줌
            ans = i;
        }
    }

    cout << ans << '\n';
}