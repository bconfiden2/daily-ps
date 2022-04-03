def bfs(pairs, total):
    visited = [[False for _ in range(N)] for _ in range(N)]
    q = []
    # 이번에 지정된 바이러스들로부터 시작
    for r, c in pairs:
        visited[r][c] = True
        q.append((r,c))
    dist, cnt = 0, len(can)
    while len(q) > 0:
        # 만약 모든 칸이 바이러스에 채워졌을 경우 종료
        if cnt == total:
            return dist
        nq = []
        for r, c in q:
            for nr, nc in ((r+1,c),(r-1,c),(r,c+1),(r,c-1)):
                if 0 <= nr < N and 0 <= nc < N and not visited[nr][nc]:
                    # 다음칸이 빈칸이든 비활성이든 똑같은 너비로 전파됨
                    if graph[nr][nc] != 1:
                        visited[nr][nc] = True
                        nq.append((nr, nc))
                        # 빈칸에 옮겨질 경우 cnt 증가
                        if graph[nr][nc] != 2: cnt += 1
        q = nq
        dist += 1
    return 10**10

from itertools import combinations
N, M = map(int, input().split())
graph = [list(map(int, input().split())) for _ in range(N)]
can = [(r,c) for r in range(N) for c in range(N) if graph[r][c] == 2]
total = N*N-sum(1 for r in range(N) for c in range(N) if graph[r][c] == 1)
ans = 10**10
# 가능한 모든 조합을 완전탐색
for pairs in combinations(can, M):
    ans = min(bfs(pairs, total), ans)
print(ans if ans != 10**10 else -1)
