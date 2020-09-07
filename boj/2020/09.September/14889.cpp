#include <iostream>

using namespace std;

int n, team_n, answer = 10e8;
int info[20][20];
bool visited[20];
int team[2][10];

int power(int t)                                    // t 로 주어지는 팀의 능력치를 반환
{
    int ret = 0;

    for(int i = 0 ; i < team_n - 1 ; i++)           // 팀을 2중반복문으로 돌리면서 능력치를 다 더함
    {
        for(int j  = i + 1 ; j < team_n ; j++)
        {
            ret += info[team[t][i]][team[t][j]];
            ret += info[team[t][j]][team[t][i]];
        }
    }

    return ret;
}

void check(int start, int size)                     // 백트래킹
{
    if(size == team_n)
    {
        for(int i = 0, idx = 0 ; i < n ; i++)       // 팀1 이 구해졌기 때문에, 팀2 를 그에 맞게 구하고
        {
            if(visited[i] == false)
                team[1][idx++] = i;
        }
        int value = abs(power(0) - power(1));       // 두 팀 능력치의 차이를 구해서
        if(value < answer) answer = value;          // 최솟값 갱신
        return;
    }
    for(int i = start + 1 ; i < n ; i++)            // 팀1 의 멤버들을 뽑는 과정
    {
        if(visited[i] == false)
        {
            visited[i] = true;
            team[0][size] = i;                      // 팀1 의 멤버목록에 추가해주고
            check(i, size + 1);                     // 재귀호출
            visited[i] = false;
        }
    }
}

/**************************************************************
int main(void)
{
    cin >> n;
    team_n = n / 2;
    for(int r = 0 ; r < n ; r++)
        for(int c = 0 ; c < n ; c++)
            cin >> info[r][c];

    check(-1, 0);

    cout << answer << endl;
}

#include <cstdio>

int n;
int a[20][20], t1[10], t2[10];
int an, bn, ans = 1e5;

void go(int x)
{
    if(ans == 0) return;
    if(x == n)
    {
        int s1 = 0, s2 = 0;
        for(int i = 0 ; i < n / 2 - 1 ; i++)
        {
            for(int j = i + 1 ; j < n / 2 ; j++)
            {
                s1 += a[t1[i]][t1[j]] + a[t1[j]][t1[i]];
                s2 += a[t2[i]][t2[j]] + a[t2[j]][t2[i]];
            }
        }
        int temp = (s1 - s2 > 0) ? (s1 - s2) : (s2 - s1);
        ans = ans > temp ? temp : ans;
        return;
    }
    if(an < n / 2)
    {
        t1[an++] = x;
        go(x + 1);
        an--;
    }
    if(bn < n / 2)
    {
        t2[bn++] = x;
        go(x + 1);
        bn--;
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
	    for (int j = 0; j < n; j++)
		    scanf("%d", &a[i][j]);
	go(0);

	printf("%d", ans);
}
***********************************************************/