def dfs(r, c, a):
    graph[r][c] = a
    for nr, nc in ((r+1,c),(r-1,c),(r,c+1),(r,c-1)):
        if 0 <= nr < R and 0 <= nc < C:
            if graph[nr][nc] == -1:
                dfs(nr, nc, a)

# 섬들별로 나눠 1번부터 번호를 붙여놓음
R, C = map(int, input().split())
graph = [list(map(lambda x:-int(x), input().split())) for r in range(R)]
area = 1
for r in range(R):
    for c in range(C):
        if graph[r][c] == -1:
            dfs(r, c , area)
            area += 1

# 각 줄(행/열)별로 검사하면서 이어지는 섬들을 에지리스트에 추가
edges = []
for r in range(R):
    cur = (-1, 0)
    for c in range(C):
        if graph[r][c] != 0:
            if cur[0] != -1 and cur[0] != graph[r][c] and c-cur[1] >= 3:
                edges.append((cur[0], graph[r][c], c-cur[1]-1))
            cur = (graph[r][c], c)
for c in range(C):
    cur = (-1, 0)
    for r in range(R):
        if graph[r][c] != 0:
            if cur[0] != -1 and cur[0] != graph[r][c] and r-cur[1] >= 3:
                edges.append((cur[0], graph[r][c], r-cur[1]-1))
            cur = (graph[r][c], r)

# 크루스칼에서 사용할 파인드 함수
parents = [i for i in range(area)]
def _find(x):
    if parents[x] == x: return x
    parents[x] = _find(parents[x])
    return parents[x]

# 에지(다리)들을 길이 순으로 검사하며 MST 형성
ans = 0
cnt = 0
for p, q, w in sorted(edges, key=lambda x:x[2]):
    if w < 2: continue
    P, Q = _find(p), _find(q)
    if P != Q:
        parents[P] = Q
        ans += w
        cnt += 1
    if cnt == area-2:
        break
print(-1 if cnt < area-2 else ans)
