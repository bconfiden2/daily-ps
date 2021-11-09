import sys
R, C = map(int, input().split())
land = [list(map(lambda x: True if x=="L" else False, line)) for line in sys.stdin]

# bfs 를 통해 특정 위치에서 가장 멀리 갈 수 있는 거리를 반환
def bfs(sr,sc, visited):
    cnt = 0
    q = [(sr,sc)]
    visited[sr][sc] = True
    while len(q) > 0:
        nq = []
        for r, c in q:
            for nr, nc in ((r+1,c),(r-1,c),(r,c+1),(r,c-1)):
                if 0 <= nr < R and 0 <= nc < C and land[nr][nc] and not visited[nr][nc]:
                    visited[nr][nc] = True
                    nq.append((nr, nc))
        q = nq
        cnt += 1
    return cnt-1

# 모든 땅에 대해서 각각 BFS 로 가장 먼 땅까지의 거리를 구함
print(max(bfs(r, c, [[False for y in range(C)] for x in range(R)]) for r in range(R) for c in range(C) if land[r][c]))