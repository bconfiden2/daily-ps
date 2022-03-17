R, C = map(int, input().split())
graph = [list(input()) for _ in range(R)]
# 가능한 [1번돌위치][2번돌위치] 조합을 모두 탐색해봤자 최대 160,000
visited = [[[[False for _ in range(21)] for _ in range(21)] for _ in range(21)] for _ in range(21)]
q = [[]]
for r in range(R):
    for c in range(C):
        if graph[r][c] == 'o':
            graph[r][c] = '.'
            q[0].append(r)
            q[0].append(c)

diri = (1,-1,0,0)
visited[q[0][0]][q[0][1]][q[0][2]][q[0][3]] = True
cnt = 0
while len(q) > 0:
    nq = []
    for r1,c1,r2,c2 in q:
        for i in range(4):
            nr1, nc1 = r1+diri[i], c1+diri[3-i]
            nr2, nc2 = r2+diri[i], c2+diri[3-i]
            # 둘다 안떨어질 경우
            if 0<=nr1<R and 0<=nc1<C and 0<=nr2<R and 0<=nc2<C:
                # 각 돌들의 다음 위치가 벽이라면, 해당 돌을 움직이지 않도록 처리
                if graph[nr1][nc1] == '#':
                    nr1, nc1 = r1, c1
                if graph[nr2][nc2] == '#':
                    nr2, nc2 = r2, c2
                # 벽에 막힌 처리 이후에, 다음 위치가 탐색되지 않았던 조합일 경우에 탐색
                if not visited[nr1][nc1][nr2][nc2]:
                    visited[nr1][nc1][nr2][nc2] = True
                    nq.append((nr1,nc1,nr2,nc2))
            # 둘 중 하나가 떨어지면 그대로 종료
            elif (0<=nr2<R and 0<=nc2<C) or (0<=nr1<R and 0<=nc1<C):
                print(cnt+1)
                exit()
            # 둘 다 떨어지는 경우는 신경쓰지 않음
    q = nq
    cnt += 1
    # 문제조건: 10번을 넘어가면 -1
    if cnt == 10:
        break
print(-1)