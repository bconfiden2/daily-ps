import sys, heapq
ipt = lambda: map(int, sys.stdin.readline().split())
for _ in range(int(input())):
    N, M, T = ipt()
    S, G, H = ipt()
    graph = [[] for _ in range(N+1)]
    dists = [10**10 for _ in range(N+1)]
    for _ in range(M):
        a, b, d = ipt()
        # 지나가야하는 에지의 경우에는 가중치를 0.1 만큼 빼줌
        # 해당 경로를 지날 경우 최단거리가 실수형이 됨
        if a in (G,H) and b in (G,H):
            d -= 0.1
        graph[a].append((b, d))
        graph[b].append((a, d))
    # 가중치 보정을 한 뒤 일반적인 다익스트라로 모든 노드들에 대한 최단거리 구함
    dists[S] = 0
    q = [(0, S)]
    while len(q):
        curd, cur = heapq.heappop(q)
        if curd > dists[cur]: continue
        for nxt, nd in graph[cur]:
            nxtd = curd + nd
            if dists[nxt] > nxtd:
                dists[nxt] = nxtd
                heapq.heappush(q, (nxtd, nxt))
    # 후보들 중에 거리가 실수형인(g-h)를 지난 노드들 출력
    ans = []
    for _ in range(T):
        x = int(sys.stdin.readline())
        if type(dists[x]) == float:
            ans.append(x)
    print(" ".join(map(str, sorted(ans))))