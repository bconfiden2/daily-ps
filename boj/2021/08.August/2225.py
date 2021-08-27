N, K = map(int, input().split())
# DP[N][K] = 정수 K 개로 합이 N 이 되는 경우의 수
DP = [[1 for k in range(K+1)] for n in range(N+1)]
for n in range(1, N+1):
    for k in range(2, K+1):
        # DP[n][k] = DP[0][k-1] + DP[1][k-1] + ... DP[n][k-1]
        DP[n][k] = sum(DP[i][k-1] for i in range(n+1)) % 1000000000
print(DP[N][K])