import sys, heapq
inp = lambda: map(int, sys.stdin.readline().split())
for _ in range(int(input())):
    N, D, c = inp()
    graph = [[] for _ in range(N)]
    for d in range(D):
        a, b, s = inp()
        graph[b-1].append((a-1, s))
    dist = [10e10 for _ in range(N)]
    pq = [(0, c-1)]
    ans = dist[c-1] = 0
    # 다익스트라로 먼저 방문 가능한 노드들 순으로 탐색
    while len(pq) > 0:
        curdist, cur = heapq.heappop(pq)
        if curdist > dist[cur]:
            continue
        ans = curdist
        for nxt, dt in graph[cur]:
            nxtdist = curdist + dt
            if nxtdist < dist[nxt]:
                dist[nxt] = nxtdist
                heapq.heappush(pq, (nxtdist, nxt))
    # 방문했던 노드들의 수와 최단거리 출력
    print(sum(int(v!=10e10) for v in dist), ans)
