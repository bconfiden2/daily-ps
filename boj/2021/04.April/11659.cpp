#include <stdio.h>

int N, M, temp;
int l, r;
int cumsum[100001];

int main(void)
{
    scanf("%d %d", &N, &M);
    for(int i = 1 ; i <= N ; i++)
    {
        scanf("%d", &temp);
        cumsum[i] = cumsum[i-1] + temp;              // i 까지의 누적합을 저장
    }
    for(int i = 0 ; i < M ; i++)
    {
        scanf("%d %d", &l, &r);
        printf("%d\n", cumsum[r] - cumsum[l-1]);    // l 과 r 구간의 합은 r 까지 누적합 - l 전까지의 누적합
    }
}