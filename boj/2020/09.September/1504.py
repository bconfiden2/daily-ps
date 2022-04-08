import sys, heapq
input = lambda: map(int, sys.stdin.readline().split())
INF = 10**10
N, E = input()
graph = [[] for _ in range(N+1)]
for _ in range(E):
    a, b, c = input()
    graph[a].append((b, c))
    graph[b].append((a, c))
v1, v2 = input()

# 일반 다익스트라
def dijkstra(s, e):
    dist = [INF for _ in range(N+1)]
    dist[s] = 0
    pq = [(0, s)]
    while len(pq) > 0:
        curdist, cur = heapq.heappop(pq)
        if cur == e: return curdist
        if curdist > dist[cur]: continue
        for nxt, nd in graph[cur]:
            nxtdist = curdist + nd
            if nxtdist < dist[nxt]:
                dist[nxt] = nxtdist
                heapq.heappush(pq, (nxtdist, nxt))
    return INF

# 1 - v1 - v2 - N
# 1 - v2 - v1 - N  두 경로 중 더 짧은 곳으로
ans1 = dijkstra(1, v1) + dijkstra(v1, v2) + dijkstra(v2, N)
ans2 = dijkstra(1, v2) + dijkstra(v2, v1) + dijkstra(v1, N)
print(min(ans1, ans2) if min(ans1, ans2) < INF else -1)