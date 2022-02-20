import sys
sys.setrecursionlimit(1000000)
R, C = map(int, input().split())
graph = [list(map(lambda x: -int(x), line.strip())) for line in sys.stdin]

def dfs(r, c, area):
    graph[r][c] = area
    ret = 1
    for nr, nc in ((r+1,c),(r-1,c),(r,c+1),(r,c-1)):
        if 0 <= nr < R and 0 <= nc < C and graph[nr][nc] == 0:
            ret += dfs(nr, nc, area)
    return ret

# 빈칸들을 구역별로 나눈뒤, 각 구역의 빈칸 개수를 딕셔너리로 유지
act = dict()
area = 1
for r in range(R):
    for c in range(C):
        if graph[r][c] == 0:
            act[area] = dfs(r, c, area)
            area += 1

# 벽이 있었던 위치일 경우, 4개 방향에 존재하던 빈칸 구역들에 대해 해당 구역은 이동가능
for r in range(R):
    ans = ""
    for c in range(C):
        if graph[r][c] > 0:
            ans += "0"
        else:
            tmp = set()
            for nr, nc in ((r+1,c),(r-1,c),(r,c+1),(r,c-1)):
                if 0 <= nr < R and 0 <= nc < C and graph[nr][nc] > 0:
                    tmp.add(graph[nr][nc])
            ans += str((sum(act[area] for area in tmp)+1) % 10)
    print(ans)