C, N = map(int, input().split())
arr = [tuple(map(int, input().split())) for _ in range(N)]
# dp[i] = i명을 늘이기 위해 투자해야하는 돈의 최소값
dp = [10**5 for _ in range(C+101)]
dp[0] = 0

for i in range(C):
    # i 명인 상황에서, 각 도시에 홍보함으로써 갱신될 수 있는 최소값 확보
    for cost, num in arr:
        dp[i+num] = min(dp[i+num], dp[i]+cost)
# 최소 C명 늘리는 것이기 때문에 C명 이상일 때의 최소값 출력
print(min(dp[C:]))
