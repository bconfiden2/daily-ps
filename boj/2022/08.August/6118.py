import sys
N, M = map(int, input().split())
graph = [[] for _ in range(N)]
for line in sys.stdin:
    a, b = map(lambda x:int(x)-1, line.strip().split())
    graph[a].append(b)
    graph[b].append(a)

dist = [0] + [-1 for _ in range(N-1)]
q = [0]
while len(q):
    nq = []
    for cur in q:
        curdist = dist[cur]
        for nxt in graph[cur]:
            if dist[nxt] == -1:
                dist[nxt] = curdist + 1
                nq.append(nxt)
    q = nq

ans = max(dist)
for i in range(N):
    if dist[i] == ans:
        print(f"{i+1} {ans} {sum(1 for v in dist if v==ans)}")
        break