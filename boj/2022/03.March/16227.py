import sys, heapq
N, K = map(int, input().split())
graph = [[] for _ in range(N+2)]
for line in sys.stdin:
    u, v, t = map(int, line.split())
    graph[u].append((v, t))
    graph[v].append((u, t))

distance = [10**10] * (N+2)
q = [(0,0,0)]
distance[0] = 0
while len(q) > 0:
    cdist, cstat, cur = heapq.heappop(q)
    if distance[cur] < cdist: continue
    for nxt, nd in graph[cur]:
        if cstat+nd <= 100:
            if cdist+nd < distance[nxt]:
                distance[nxt] = cdist+nd
                heapq.heappush(q, (cdist+nd, cstat+nd, nxt))
        elif nd <= 100:
            if cdist+nd+5 < distance[nxt]:
                distance[nxt] = cdist+nd+5
                heapq.heappush(q, (cdist+nd+5, nd, nxt))
print(distance[N+1])

