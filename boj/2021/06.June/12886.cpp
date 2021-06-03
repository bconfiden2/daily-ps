#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct Stones
{
    int abc[3];
};

int A, B, C, X, Y;
int visited[1000][1000];            // 세 그룹 중 작은 순서대로 앞에 2개를 보는 방문 배열

int main(void)
{
    cin >> A >> B >> C;

    if((A + B + C) % 3 != 0)        // 애초에 세 그룹으로 못 나눌 경우
    {
        cout << 0 << endl;
        return 0;
    }

    queue<Stones> q;
    Stones start = {{A,B,C}};
    sort(start.abc, start.abc + 3);
    visited[start.abc[0]][start.abc[1]] = true;
    q.push(start);  

    while(q.size())
    {
        int cur[3];
        copy(q.front().abc, q.front().abc+3, cur);
        q.pop();
        if(cur[0] == cur[1] && cur[1] == cur[2])
        {
            cout << 1 << endl;
            return 0;
        }
        for(int i = 0 ; i < 3 ; i++)
        {
            int nxt[3];
            copy(cur, cur+3, nxt);
            X = (i == 2 ? nxt[0] : nxt[i]);
            Y = (i == 2 ? nxt[2] : nxt[i+1]);           // 정렬된 배열에서 가장 작은 2개를 뽑아서
            nxt[i%3] = X + X;
            nxt[(i+1)%3] = Y - X;                       // 로직에 맞는 연산
            sort(nxt, nxt+3);                           // 3개 숫자 정렬
            if(!visited[nxt[0]][nxt[1]])                // 어차피 정렬했을 때 가장 작은 두개가 결정되면 나머지 하나도 자동 결정
            {                                           // 가장 작은 2개에 대한 집합으로 중복 처리 관리
                visited[nxt[0]][nxt[1]] = true;
                q.push({{nxt[0], nxt[1], nxt[2]}});
            }
        }
    }
    cout << 0 << endl;
}