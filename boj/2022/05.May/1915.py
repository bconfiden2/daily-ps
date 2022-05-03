R, C = map(int, input().split())
D = min(R, C)
# dp[r][c] = r,c 위치에서 가능한 최대 정사각형 크기
dp = [list(map(int, input())) for _ in range(R)]
for r in range(1, R):
    for c in range(1, C):
        # 특정 위치에 값이 들어있을 경우
        if dp[r][c] == 1:
            # 해당 위치 기준 (위, 아래, 왼위의 정사각형 크기들 중 최소값) + 1
            dp[r][c] = min(dp[r-1][c-1], dp[r][c-1], dp[r-1][c]) + 1
print(max(max(row) for row in dp) ** 2)
