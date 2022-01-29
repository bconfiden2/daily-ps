import sys
N = int(input())
mat = [tuple(map(int, L.split())) for L in sys.stdin]
dp = [[0 for c in range(N+1)] for r in range(N)]

# dp[r][c] = r위치에서 c개만큼의 최소연산횟수
for c in range(2, N+1):
    for r in range(N):
        if r > N-c: continue
        mini = 2**31-1
        # c개의 최소값은, ((c-1,1) (c-2,2) ... (1,c-1)) 들 중 최소값
        for p in range(c-1, 0, -1):
            q = c - p
            v = dp[r][p] + dp[r+c-q][q] + mat[r][0]*mat[r+p][0]*mat[r+c-1][1]
            if v < mini:
                mini = v
        dp[r][c] = mini

print(dp[0][N])