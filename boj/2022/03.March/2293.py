n, k = map(int, input().split())
# dp[i] = 이전 동전들까지만을 사용했을때 k 를 만드는 경우의 수 + 이번 동전까지 포함해서 사용했을 때 k를 만드는 경우의 수
dp = [1] + [0 for _ in range(k)]
# 모든 비용들에 대해서 하나씩 추가할때마다 k를 만드는 경우의 수가 어떻게 갱신되는지 확인
for c in sorted(int(input()) for _ in range(n)):
    for i in range(1, k+1):
        if i >= c: dp[i] += dp[i-c]
print(dp[k])