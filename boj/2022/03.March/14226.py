S = int(input())
# visited[현재화면][클립보드]
visited = [[False for c in range(S+1)] for d in range(S+1)]
q = [(1,0)]
ans = 0
visited[1][0] = True
# bfs 로 목표하는 S까지의 최단거리
while len(q) > 0:
    nq = []
    for t, p in q:
        if t == S:
            print(ans)
            exit()
        # 3가지 선택지 중 하나 골라가기
        for nt, np in ((t,t),(t+p,p),(t-1,p)):
            if 0 <= nt <= S and not visited[nt][np]:
                visited[nt][np] = True
                nq.append((nt,np))
    q = nq
    ans += 1