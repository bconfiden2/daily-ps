import sys
sys.setrecursionlimit(100000)
input = sys.stdin.readline
R, C, K = map(int, input().split())
graph = [[False for c in range(C)] for r in range(R)]
for k in range(K):
    r, c = map(int, input().split())
    graph[r-1][c-1] = True

def dfs(r, c):
    cnt = 1
    graph[r][c] = False
    for nr, nc in ((r+1,c),(r-1,c),(r,c+1),(r,c-1)):
        if 0 <= nr < R and 0 <= nc < C:
            if graph[nr][nc]:
                cnt += dfs(nr, nc)
    return cnt

answer = 0
for r in range(R):
    for c in range(C):
        if graph[r][c]:
            answer = max(answer, dfs(r, c))
print(answer)