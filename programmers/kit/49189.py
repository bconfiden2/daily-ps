def solution(n, edge):
    graph = [[] for _ in range(n+1)]
    for a, b in edge:
        graph[a].append(b)
        graph[b].append(a)
    visited = [-1 for _ in range(n+1)]
    q = [1]
    cnt = 0
    # 1번 노드부터 시작해서 bfs로 노드들 탐색
    while len(q) > 0:
        nq = []
        for cur in q:
            visited[cur] = cnt
            for nxt in graph[cur]:
                if visited[nxt] == -1:
                    visited[nxt] = True
                    nq.append(nxt)
        cnt += 1
        q = nq
    ans = max(visited)
    # 최대거리인 노드들 개수 반환
    return sum(1 for v in visited if v==ans)