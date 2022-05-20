import sys
ipt = lambda: map(int, sys.stdin.readline().split())

N, K = ipt()
# dp[p][q] = p가 q보다 먼저 발생한 경우 -1, 모를 경우 0, 늦을 경우 1
dp = [[0 for _ in range(N+1)] for _ in range(N+1)]
for _ in range(K):
    p, q = ipt()
    dp[p][q] = -1
    dp[q][p] = 1

for k in range(1, N+1):
    for r in range(1, N+1):
        for c in range(1, N+1):
            # 만약 전후 비교가 가능한 노드를 거쳐서 연결되는 경우
            if dp[r][k] != 0 and dp[r][k] == dp[k][c]:
                # 해당 전후 상태를 그대로 상속받음
                dp[r][c] = dp[r][k]

ans = []
for _ in range(int(input())):
    p, q = ipt()
    ans.append(str(dp[p][q]))
print('\n'.join(ans))