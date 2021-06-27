#include <iostream>

using namespace std;

int n, m, a, b, pa, pb;
int parents[500001];

int find_(int cur)                      // 경로 압축을 통한 유니온 파인드
{
    if(parents[cur] == -1) return cur;
    parents[cur] = find_(parents[cur]);
    return parents[cur];
}

int main(void)
{
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++) parents[i] = -1;
    for(int i = 0 ; i < m ; i++)
    {
        cin >> a >> b;
        pa = find_(a);
        pb = find_(b);
        if(pa == pb)                    // 싸이클이 형성되면 바로 종료
        {
            cout << i+1 << endl;
            return 0;
        }
        parents[pa] = pb;               // 유니온 부분, 따로 구현 x
    }
    cout << 0 << endl;
}