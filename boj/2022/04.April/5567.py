import sys
n = int(input())
m = int(input())
graph = [[] for _ in range(n+1)]
visited = [False for _ in range(n+1)]
for line in sys.stdin:
    a, b = map(int, line.split())
    graph[a].append(b)
    graph[b].append(a)

visited[1] = True
q = [1]
ans = 0
for _ in range(2):
    nq = []
    for cur in q:
        for nxt in graph[cur]:
            if not visited[nxt]:
                nq.append(nxt)
                visited[nxt] = True
    ans += len(nq)
    q = nq
print(ans)