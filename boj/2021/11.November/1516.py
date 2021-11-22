import sys, heapq
N = int(input())
degree = [0 for _ in range(N+1)]
costs = [0 for _ in range(N+1)]
graph = [[] for _ in range(N+1)]
# 각 노드별 건설비용, in-degree, 정방향그래프 저장
for i, line in enumerate(sys.stdin):
    adj = list(map(int, line.split()[:-1]))
    costs[i+1] = adj[0]
    degree[i+1] = len(adj) - 1
    for x in adj[1:]:
        graph[x].append(i+1)

# 차수가 0 인 시작노드들 담은 뒤
hq = []
for i, v in enumerate(degree):
    if v == 0 and i > 0:
        heapq.heappush(hq, (costs[i], i))
# 위상 정렬로 하나씩 탐색해나감
answer = [0 for _ in range(N+1)]
while len(hq) > 0:
    cost, node = heapq.heappop(hq)
    answer[node] = cost
    for nxt in graph[node]:
        degree[nxt] -= 1
        if degree[nxt] == 0:
            heapq.heappush(hq, (cost+costs[nxt], nxt))

for ans in answer[1:]:
    print(ans)