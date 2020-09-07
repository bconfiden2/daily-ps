#include <iostream>
#include <queue>

using namespace std;

int n, k;

int main()
{
    cin >> n >> k;
    queue<int> q;

    for(int i = 1 ; i <= n ; i++)
    {
        q.push(i);
    }
    cout << "<";
    while(q.size() > 1)
    {
        for(int i = 0 ; i < k - 1 ; i++)        // 앞에서부터 K - 1 명의 사람들을 뒤로 보낸다
        {
            q.push(q.front());
            q.pop();
        }
        cout << q.front() << ", ";              // 그러면 순서대로 제거해야 되는 K 번째 사람이 앞에 남기 때문에
        q.pop();                                // 출력하고 제거
    }
    cout << q.front() << ">" << endl;
}


/*************************************************************
#include <cstdio>

using namespace std;

int main()
{
    int d[5001];
    int n, k;
    int now = 0;
    scanf("%d %d", &n, &k);
    for(int i = 1 ; i <= n ; i++) d[i] = i;
    printf("<");

    while(n > 1)
    {
        now = (now + k) % n;
        if(now == 0) now = n;
        
        printf("%d, ", d[now]);
        for(int i = now ; i < n ; i++) d[i] = d[i+1];
        now--;
        n--;
    }
    printf("%d>\n", d[1]);
}
**************************************************************/