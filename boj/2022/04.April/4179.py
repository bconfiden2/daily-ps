R, C = map(int, input().split())
jq, fq = [], []
graph = []
visited = [[False for _ in range(C)] for _ in range(R)]
for r in range(R):
    row = []
    for c, v in enumerate(input()):
        if v == 'J':
            row.append(True)
            jq.append((r, c))
            visited[r][c] = True
        elif v == 'F':
            row.append(False)
            fq.append((r, c))
        else:
            row.append(True if v=='.' else False)
    graph.append(row)

cnt = 0
while len(jq):
    cnt += 1
    # 불이 먼저 확산된 이후에
    nq = []
    for r, c in fq:
        for nr, nc in ((r+1,c),(r-1,c),(r,c+1),(r,c-1)):
            if 0 <= nr < R and 0 <= nc < C and graph[nr][nc]:
                graph[nr][nc] = False
                nq.append((nr, nc))
    fq = nq
    # 지훈이가 이동함
    nq = []
    for r, c in jq:
        for nr, nc in ((r+1,c),(r-1,c),(r,c+1),(r,c-1)):
            if 0 <= nr < R and 0 <= nc < C:
                # 다음 위치가 불/벽이거나 이전에 방문했던 곳이면 스킵
                if graph[nr][nc] and not visited[nr][nc]:
                    visited[nr][nc] = True
                    nq.append((nr, nc))
            # 지훈이가 미로에서 벗어난 경우
            else:
                print(cnt)
                exit()
    jq = nq
print("IMPOSSIBLE")