import sys, heapq
it = lambda : map(int, sys.stdin.readline().split())
N, M, R = it()
graph = [[] for _ in range(N)]
for m in range(M):
    u, v = it()
    graph[u-1].append(v-1)
    graph[v-1].append(u-1)

# 수도코드대로 구현해야함!
q = [R-1]
answer, cnt = ["0" for _ in range(N)], 1
visited = [False for _ in range(N)]
visited[R-1] = True
while len(q) > 0:
    nq = []
    for cur in q:
        answer[cur] = str(cnt)
        cnt += 1
        for nxt in sorted(graph[cur]):
            if not visited[nxt]:
                visited[nxt] = True
                nq.append(nxt)
    q = nq
print("\n".join(answer))