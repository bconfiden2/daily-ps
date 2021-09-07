import sys
sys.setrecursionlimit(100000)

# dfs 를 통해 노드 n 의 dp값을 구함
def dfs(n, graph, D, dp, visited):
    visited[n] = True
    # 노드 n에 대한 방문 처리 후, n을 건설하는데 드는 기본값으로 초기화
    dp[n] += D[n]
    for nxt in graph[n]:
        # 이전에 방문하지 않았던 노드들에 대해서만 새롭게 탐색
        if not visited[nxt]:  
            dfs(nxt, graph, D, dp, visited)
        # dp[n]은, n에 연결된 모든 노드(역방향)들 중 n에 도달하기까지의 최대값
        dp[n] = max(dp[n], dp[nxt]+D[n])

for tc in range(int(input())):
    N, K = map(int, input().split())
    D = [-1] + list(map(int, input().split()))
    dp = [0 for i in range(N+1)]
    rev_graph = [[] for i in range(N+1)]
    visited = [False for i in range(N+1)]
    # 그래프를 역방향으로 저장(뒤집기)
    for i in range(K):
        X, Y = map(int, sys.stdin.readline().split())
        rev_graph[Y].append(X)
    W = int(input())
    # 목표지점 W 부터 dfs 탐색 시작
    dfs(W, rev_graph, D, dp, visited)
    print(dp[W])