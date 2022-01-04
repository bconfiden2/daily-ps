import sys
sys.setrecursionlimit(50000)
n = int(input())
forest = [list(map(int, line.split())) for line in sys.stdin]
dp = [[-1 for _ in range(n)] for i in range(n)]

# 특정 위치에서 시작하여 dfs 탐색하며 방문 가능한 노드 모두 검사
def dfs(r, c):
    tmp = 0
    # 4방향 중 이동가능한 방향 중에
    for nr, nc in ((r+1,c),(r-1,c),(r,c+1),(r,c-1)):
        if 0 <= nr < n and 0 <= nc < n:
            if forest[nr][nc] > forest[r][c]:
                # 만약 이미 검사됐던 위치라면 해당 dp 값 그대로 가져오고, 아니면 dfs 탐색
                tmp = max(tmp, dp[nr][nc] if dp[nr][nc] != -1 else dfs(nr,nc))
    # 현재 위치의 dp값 = 4방향 중 최대값 + 1(현위치)
    dp[r][c] = tmp + 1
    return dp[r][c]

# 모든 노드에 대해서 검사 후 최대값 출력
print(max(dfs(i,j) for i in range(n) for j in range(n) if dp[i][j] != -1))