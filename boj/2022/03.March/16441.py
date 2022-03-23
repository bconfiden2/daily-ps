R, C = map(int, input().split())
graph = [list(input()) for _ in range(R)]
ans = [[v for v in row] for row in graph]
diri = (1, -1, 0, 0)

q = []
visited = [[False for _ in range(C)] for _ in range(R)]
for r in range(R):
    for c in range(C):
        if graph[r][c] == 'W':
            q.append((r, c))
            visited[r][c] = True
            graph[r][c] = '.'

# 미끄러지기 구현
def goto(r, c, i):
    nr, nc = r+diri[i], c+diri[3-i]
    while True:
        # 인덱스를 벗어나거나 벽을 만날 경우 그자리에서 정지
        if not (0 <= nr < R and 0 <= nc < C) or graph[nr][nc] == '#': return r, c
        # 미끄러지다가 초원에 도착할 경우 해당 자리에 정지
        if graph[nr][nc] == '.': return nr, nc
        # 다음 칸으로 이동
        r, c = nr, nc
        nr, nc = r+diri[i], c+diri[3-i]

# bfs로 늑대가 갈 수 있는 모든 위치 탐색
while len(q) > 0:
    nq = []
    for r, c in q:
        for i in range(4):
            nr, nc = r+diri[i], c+diri[3-i]
            if 0 <= nr < R and 0 <= nc < C and graph[nr][nc] != '#':
                if graph[nr][nc] == '+':
                    nr, nc = goto(nr, nc, i)
                if not visited[nr][nc]:
                    visited[nr][nc] = True
                    nq.append((nr, nc))
    q = nq

for r in range(R):
    for c in range(C):
        if not visited[r][c] and graph[r][c] == '.':
            ans[r][c] = 'P'
for row in ans:
    print("".join(row))