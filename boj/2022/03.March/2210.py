def dfs(r, c, path):
    path += graph[r][c]
    if len(path) == 6:
        ans.add(path)
        return
    for nr, nc in ((r+1,c),(r-1,c),(r,c+1),(r,c-1)):
        if 0 <= nr < 5 and 0 <= nc < 5:
            dfs(nr, nc, path)    

ans = set()
graph = [input().split() for _ in range(5)]
# 각 위치에서 가능한 모든 경로 검사
for r in range(5):
    for c in range(5):
        dfs(r, c, "")
print(len(ans))