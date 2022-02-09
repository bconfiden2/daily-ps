import sys
input = sys.stdin.readline
for _ in range(int(input())):
    R, C = map(int, input().split())
    graph = [list(input().strip()) for r in range(R)]
    sq = []
    # 가장자리 중에서 가능한 시작지점 모두 탐색
    for r in range(R):
        if graph[r][0] != '*': sq.append((r,0))
        if graph[r][C-1] != '*': sq.append((r,C-1))
    for c in range(1, C-1):
        if graph[0][c] != '*': sq.append((0,c))
        if graph[R-1][c] != '*': sq.append((R-1,c))
    svisited = [[False for c in range(C)] for r in range(R)]
    keys = set(list(input().strip()))
    for r,c in sq:
        svisited[r][c] = True
    

    ans = 0
    # 이번 탐색에서 열쇠를 먹었을 경우, 전체 빌딩을 다시 탐색
    while True:
        end = True
        q, visited = sq.copy(), [[v for v in row] for row in svisited]
        while len(q) > 0:
            nq = []
            for r,c in q:
                # 열쇠를 먹은 경우
                if ord(graph[r][c]) >= 97:
                    keys.add(graph[r][c])
                    graph[r][c] = '.'
                    end = False
                # 문에 도달했는데
                elif ord(graph[r][c]) >= 65:
                    # 열쇠가 없으면 그냥 넘어감
                    if graph[r][c].lower() not in keys: continue
                    # 열쇠를 갖고 있었으면 방문처리
                    else: graph[r][c] = '.'
                # 문서를 먹은 경우
                elif graph[r][c] == '$':
                    graph[r][c] = '.'
                    ans += 1
                for nr, nc in ((r+1,c),(r-1,c),(r,c+1),(r,c-1)):
                    if 0 <= nr < R and 0 <= nc < C and not visited[nr][nc]:
                        if graph[nr][nc] != '*':
                            visited[nr][nc] = True
                            nq.append((nr, nc))
            q = nq
        if end: break
    print(ans)