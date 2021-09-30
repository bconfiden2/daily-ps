import sys
read = sys.stdin.readline
N, M = map(int, read().split())
weights = []
graph = [{} for i in range(N+1)]
for _ in range(M):
    # 그래프를 양방향으로 연결하면서, 중복되는 다리에 대해선 그들 중 최댓값만을 선택
    v, u, w = map(int, read().split())
    graph[v][u] = max(graph[v].get(u, 0), w)
    graph[u][v] = max(graph[u].get(v, 0), w)
    weights.append(w)
for i, dic in enumerate(graph):
    graph[i] = list(dic.items())
sta, end = map(int, read().split())
weights.sort()

# 입력받은 중량을 가지고 목적지에 도달할 수 있는지 판별하는 bfs 함수
def bfs(w):
    global sta, end
    visited = [False for i in range(N+1)]
    q = [sta]
    visited[sta] = True
    while len(q) > 0:
        nq = []
        for cur in q:
            if cur == end:
                return True
            for nxt, nxtd in graph[cur]:
                if not visited[nxt] and nxtd >= w:
                    visited[nxt] = True
                    nq.append(nxt)
        q = nq
    return False

# 가능한 모든 중량들에 대해서 이진탐색으로 bfs 를 돌려서, 최대한 높은 값을 정답으로 선택
ldx, rdx = 0, len(weights)-1
while ldx <= rdx:
    mdx = (ldx+rdx) // 2
    if bfs(weights[mdx]):
        ldx = mdx + 1
    else:
        rdx = mdx - 1
print(weights[rdx])