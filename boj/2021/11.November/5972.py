import sys, heapq
N, M = map(int, input().split())
# 간선들 양방향으로 연결한 그래프
graph = [[] for _ in range(N+1)]
for line in sys.stdin:
    a, b, c = map(int, line.split())
    graph[a].append((b, c))
    graph[b].append((a, c))

d = [10e8 for _ in range(N+1)]
pq = [(0, 1)]
d[1] = 0
# 시작지점 1번부터, N번 노드에 도착할때까지 다익스트라로 최단 거리 구하기
while len(pq) > 0:
    dist, cur = heapq.heappop(pq)
    if cur == N:
        print(dist)
        break
    if d[cur] < dist:
        continue
    for nxt, ndist in graph[cur]:
        if ndist + dist < d[nxt]:
            d[nxt] = ndist + dist
            heapq.heappush(pq, (d[nxt], nxt))