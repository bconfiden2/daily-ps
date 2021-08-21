import sys
import heapq

N = int(input())
M = int(input())
# 도시 연결된 그래프 생성
graph = [[] for _ in range(N+1)]
for _ in range(M):
	a, b, w = map(int, input().split())
	graph[a].append((b,w))
P, Q = map(int, input().split())

# 일반적인 다익스트라와 동일
pq = [(0, P)]
distance = [10e9 for _ in range(N+1)]
distance[P] = 0

while len(pq) > 0:
	curdist, curnode = pq[0]
	heapq.heappop(pq)
	if curnode == Q: break
	if distance[curnode] < curdist: continue
	for nextnode, nextdist in graph[curnode]:
		if curdist+nextdist < distance[nextnode]:
			distance[nextnode] = curdist+nextdist
			heapq.heappush(pq, (curdist+nextdist, nextnode))
print(distance[Q])
