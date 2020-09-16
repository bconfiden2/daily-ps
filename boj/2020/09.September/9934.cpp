#include <iostream>

using namespace std;

int k, number;
int order[1024];        // 입력값 순서 배열
int answer[1024];       // 1을 루트노드로 한 노드 순서 배열
int count = 0;

void Seek(int idx, int depth)
{
    if(depth == k)                      // 마지막 층이라면
    {
        answer[idx] = order[count++];   // 해당 노드만 값 넣어주고 끝
    }
    else
    {                                   // 마지막 층이 아니라면
        Seek(idx * 2, depth + 1);       // 왼쪽 자식노드 검사
        answer[idx] = order[count++];   // 현재 노드값 검사, count 증가값에 따라 순서대로 들어가기 때문에 순서가 중요
        Seek(idx * 2 + 1, depth + 1);   // 오른쪽 자식노드 검사
    }
}

int main()
{
    cin >> k;
    number = (1 << k) - 1;
    for(int i = 0 ; i < number ; i++) cin >> order[i];

    Seek(1, 1);

    for(int n = 0, idx = 1 ; n < k ; n++)   // 층별로 출력하기
    {
        for(int i = 0 ; i < 1 << n ; i++)
        {
            cout << answer[idx++] << ' ';
        }
        cout << '\n';
    }
}

/****************************************************************
#include <stdio.h>

int main()
{
    int k;
    int pow[11];
    int ans[12][1101];
    int c[12][1101];

    pow[0] = 1;
    for(int i = 1 ; i <= 10 ; i++)
    {
        pow[i] = pow[i-1] * 2;
    }

    scanf("%d", &k);
    for(int i = 1 ; i <= pow[k] - 1 ; i++)
    {
        scanf("%d", &c[k+1][i]);
    }

    for(int i = k ; i >= 1 ; i++)
    {
        for(int j = 1 ; j <= pow[i]-1 ; j++)
        {
            if(j % 2) ans[i][(j+1)/2] = c[i+1][j];
            else c[i][j/2] = c[i+1][j];
        }
    }

    for(int i = 1 ; i <= k ; i++)
    {
		for(int j = 1 ; j <= pow[i-1] ; j++)
        {
			printf("%d ", ans[i][j]);
		}
		printf("\n");
	}
}
*****************************************************************/