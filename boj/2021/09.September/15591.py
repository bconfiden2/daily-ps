import sys
N, Q = map(int, sys.stdin.readline().split())
ln = [[] for _ in range(N+1)]

# 그래프에 양방향으로 연결, 에지가 N-1 이기 때문에 노드들이 반드시 일직선으로 연결됨
for _ in range(N-1):
    p, q, r = map(int, sys.stdin.readline().strip().split())
    ln[p].append((q,r))
    ln[q].append((p,r))

for _ in range(Q):
    k, v = map(int, sys.stdin.readline().split())
    # 입력 받은 노드 v 로부터 bfs를 통해 양쪽으로 탐색해나감
    visited = [False for _ in range(N+1)]
    visited[v] = True
    cnt = 0
    q = ln[v][:]

    while len(q) > 0:
        nq = []
        for cur, dist in q:
            visited[cur] = True
            # 현재까지의 최소 유사도가 k 이상일 경우에 카운트 증가시켜주고, 연결된 노드 계속 탐색
            if dist >= k:
                cnt += 1
                # 현재 최소값이 k 보다 작으면, 이후에 연결된 모든 노드들의 최소값은 k 보다 무조건 작음
                for nxt, ndist in ln[cur]:
                    if visited[nxt]: continue
                    visited[nxt] = True
                    nq.append((nxt, min(dist, ndist)))
        q = nq
    print(cnt)