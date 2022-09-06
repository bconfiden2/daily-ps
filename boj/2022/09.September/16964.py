import sys
input = sys.stdin.readline

N = int(input())
graph = [[] for _ in range(N+1)]
for _ in range(N-1):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)
order = list(map(int, input().split()))
idx = 0

visited = [False for _ in range(N+1)]
def dfs(x):
    global idx
    idx += 1
    visited[x] = True
    vct = sum(1 for v in graph[x] if visited[v])
    for _ in range(len(graph[x])):
        if vct == len(graph[x]): break
        if order[idx] not in graph[x]:
            print(0)
            exit()
        if not visited[order[idx]]:
            dfs(order[idx])
            vct += 1
    
dfs(1)
print(1)