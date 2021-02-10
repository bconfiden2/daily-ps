#include <iostream>
#include <queue>

using namespace std;

int N, P;
int line, pret, count = 0;
priority_queue<int> pq[7];          // 6개 줄에 대한 각각의 우선순위큐

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> P;
    for(int i = 0 ; i < N ; i++)
    {
        cin >> line >> pret;

        while(!pq[line].empty() && pq[line].top() > pret)   // 이번에 누를 프렛보다 높은 프렛이 있으면
        {
            pq[line].pop();                                 // 손가락을 다 뗀다
            count++;
        }
        if(!pq[line].empty() && pq[line].top() == pret) continue;   // 만약 같은 프렛이면 누를필요 없으니 건너뛴다
        
        pq[line].push(pret);                               // 눌러야 하는 프렛이라면 눌러준다
        count++;
    }

    cout << count << endl;
}