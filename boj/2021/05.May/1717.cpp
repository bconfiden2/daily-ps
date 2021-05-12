#include <cstdio>
#include <vector>

using namespace std;

int n, m, t, a, b;
vector<int> idx(1000001, -1);

int find_(int cur)
{
    if(idx[cur] == -1) return cur;      // 루트일 경우 값 반환
    idx[cur] = find_(idx[cur]);         // 경로에 있는 모든 원소를 루트 바로 밑 자식으로 설정
    return idx[cur];                    // 루트 값 반환
}

void union_(int x, int y)
{
    int rt1 = find_(x);                 // 각 원소의 루트값을 받아옴
    int rt2 = find_(y);
    if(rt1 != rt2) idx[rt2] = rt1;      // 다른 집합에 속했다면 아무렇게나 집합 합쳐줌
}

int main(void)
{
    scanf("%d %d", &n, &m);
    
    for(int i = 0 ; i < m ; i++)
    {
        scanf("%d %d %d", &t, &a, &b);
        if(t) printf((find_(a) == find_(b) ? "YES\n" : "NO\n"));    // 1 일 경우 같은 집합인지 확인
        else union_(a, b);                                          // 0 일 경우 두 집합을 합쳐줌
    }
}