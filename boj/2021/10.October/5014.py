F, S, G, U, D = map(int, input().split())
visited = [False for _ in range(F+1)]
q = [S]
cnt = 0
# BFS 로 모든 층에 대해서 탐색
while len(q) > 0:
    nq = []
    for cur in q:
        if cur == G:
            print(cnt)
            exit()
        # 현위치에서 올라갈 수 있는 층
        if cur+U <= F and not visited[cur+U]:
            visited[cur+U] = True
            nq.append(cur+U)
        # 현위치에서 내려갈 수 있는 층
        if cur-D >= 1 and not visited[cur-D]:
            visited[cur-D] = True
            nq.append(cur-D)
    q = nq
    cnt += 1
print("use the stairs")