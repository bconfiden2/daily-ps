import heapq
N = int(input())
tasks = [0 for _ in range(N)]
graph = [[] for _ in range(N)]
degree = [0 for _ in range(N)]
pq = []
# 그래프 정보랑 indegree 저장
for i in range(N):
    line = input().split()
    tasks[i] = int(line[0])
    degree[i] = int(line[1])
    for v in map(int, line[2:]):
        graph[v-1].append(i)
    if degree[i] == 0:
        heapq.heappush(pq, (tasks[i], i))
# 위상정렬
cost = 0
while len(pq) > 0:
    cost, cur = heapq.heappop(pq)
    for nxt in graph[cur]:
        degree[nxt] -= 1
        if degree[nxt] == 0:
            heapq.heappush(pq, (cost+tasks[nxt], nxt))
print(cost)