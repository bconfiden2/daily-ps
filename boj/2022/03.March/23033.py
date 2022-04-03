import sys, heapq
N, M = map(int, input().split())
graph = [[] for _ in range(N)]
for line in sys.stdin:
    A, B, T, W = map(int, line.split())
    A, B = A-1, B-1
    graph[A].append((B, T, W))

distance = [10**10 for _ in range(N)]
distance[0] = 0
pq = [(0, 0)]
# 일반적인 다익스트라 방식으로 현시점에서 가장 빨리 갈 수 있는 노드들로 이동
while len(pq) > 0:
    curdist, cur = heapq.heappop(pq)
    if cur == N-1: break
    if curdist > distance[cur]: continue
    for nxt, nd, std in graph[cur]:
        nxtdist = curdist + nd
        # 다음 노드의 도착시간을 구할 때, 지하철의 출발 간격에 맞춰서 계산
        if curdist % std > 0:
            nxtdist += std - (curdist % std)
        if nxtdist < distance[nxt]:
            distance[nxt] = nxtdist
            heapq.heappush(pq, (nxtdist, nxt))
print(distance[N-1])
