N, M = map(int, input().split())
graph = [[] for _ in range(N)]
for _ in range(M):
    f1, f2 = map(lambda x: int(x)-1, input().split())
    graph[f1].append(f2)
    graph[f2].append(f1)

bakon = []
for i in range(N):
    visited = [0 for _ in range(N)]
    visited[i] = 1
    q = [i]
    dist = 1
    while q:
        pq = []
        for cur in q:
            for next in graph[cur]:
                if visited[next] == 0:
                    visited[next] = dist
                    pq.append(next)
        q = pq
        dist += 1
    bakon.append(sum(visited) - 1)

print(bakon.index(min(bakon)) + 1)
