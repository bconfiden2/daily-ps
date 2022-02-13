import sys, heapq
N, M = map(int, input().split())
graph = [[] for _ in range(N)]
degree = [0 for _ in range(N)]
for line in sys.stdin:
    A, B = map(lambda x: int(x)-1, line.split())
    graph[A].append(B)
    degree[B] += 1

# 위상정렬로 순서 보장, 그중에서도 우선순위큐로 쉬운 문제부터
pq, ans = [], []
for v in (i for i,x in enumerate(degree) if x==0):
    heapq.heappush(pq, v)
while len(pq) > 0:
    cur = heapq.heappop(pq)
    ans.append(str(cur+1))
    for nxt in graph[cur]:
        degree[nxt] -= 1
        if degree[nxt] == 0:
            heapq.heappush(pq, nxt)
print(" ".join(ans))