N = int(input())
# dp[n][i] 는, n자리 수 중에 i로 끝나는 개수
dp = [[1 for _ in range(10)] for n in range(N)]
# dp[n][i] = sum(dp[n][0] ~ dp[n][i])
for n in range(1, N):
    for i in range(1, 10):
        dp[n][i] = dp[n][i-1] + dp[n-1][i]
print(sum(dp[N-1]) % 10007)