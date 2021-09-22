N, M = map(int, input().split())
fbd = [False for _ in range(N+1)]
for _ in range(M):
    fbd[int(input())] = True

# dp[n][k] 는 n 번째 위치에 k 만큼 점프해서 도착했을 때의 점프횟수
dp = [[10000 for c in range(142)] for r in range(N+1)]
dp[2][1] = 1
for r in range(2, N+1):
    for c in range(1, 142):
        cur = dp[r][c]
        # 도달할 수 없는 돌의 위치
        if cur == 10000:
            continue
        # x-1 칸 점프
        if c > 1:
            nxt = r+c-1
            if nxt <= N and not fbd[nxt]:
                dp[nxt][c-1] = min(cur+1, dp[nxt][c-1])
        # x 칸 점프
        if r+c <= N and not fbd[r+c]:
            dp[r+c][c] = min(cur+1, dp[r+c][c])
        # x+1 칸 점프
        if c < 141:
            nxt = r+c+1
            if nxt <= N and not fbd[nxt]:
                dp[nxt][c+1] = min(cur+1, dp[nxt][c+1])

# N 번째 위치까지 도달한 경로 중 최소값 출력
answer = min(dp[N])
print(answer if answer != 10000 else -1)