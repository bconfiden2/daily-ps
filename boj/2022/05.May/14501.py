N = int(input())
arr = [tuple(map(int, input().split())) for _ in range(N)]
dp = [0 for _ in range(N+1)]
for i, (T, P) in enumerate(arr):
    # 현재 위치 dp를 현재까지의 최대값으로 갱신한 뒤
    if i > 0:
        dp[i] = max(dp[i], max(dp[:i]))
    # 현위치에서 가능한 최대값 + 이번에 상담을 할 시 발생하는 위치에 값 갱신
    if i+T <= N:
        dp[i+T] = max(dp[i+T], dp[i]+P)
print(max(dp))
