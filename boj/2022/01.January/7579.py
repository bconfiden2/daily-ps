N, M = map(int, input().split())
mem = list(map(int, input().split()))
cost = list(map(int, input().split()))
total = sum(cost)
dp = [0 for _ in range(total+1)]
# dp[i] = 총 비용 i 만큼으로 확보 가능한 메모리의 최대값
for n in range(N):
    for i in range(total, cost[n]-1, -1):
        dp[i] = max(dp[i-cost[n]] + mem[n], dp[i])
# 메모리를 M 이상 확보 가능한 비용들 중 최소비용 출력
for i,v in enumerate(dp):
    if v >= M:
        print(i)
        break