import sys
input = sys.stdin.readline

N = int(input())
mode = [input().strip() for _ in range(N)]
start, end = map(lambda x: int(x)-1, input().split())
graph = [[] for _ in range(N)]
# 모든 노드들에 대해서 서로 연결시켜줌
for i in range(N):
    for j in range(i+1, N):
        dist = sum((int(c1)-int(c2))**2 for c1, c2 in zip(mode[i], mode[j]))
        graph[i].append((j, dist))
        graph[j].append((i, dist))

# 일반적인 다익스트라
import heapq
pq = [(0, start)]
distances = [10e9 for i in range(N)]
distances[start] = 0
while len(pq) > 0:
    curdist, cur = heapq.heappop(pq)
    if cur == end:
        print(curdist)
        break
    if curdist > distances[cur]:
        continue
    for nxt, nxtdist in graph[cur]:
        if curdist+nxtdist < distances[nxt]:
            heapq.heappush(pq, (curdist+nxtdist, nxt))
            distances[nxt] = curdist+nxtdist