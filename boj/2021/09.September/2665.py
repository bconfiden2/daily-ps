N = int(input())
room = [list(map(lambda x:(int(x)+1)%2, input())) for r in range(N)]
answer = [[10e8 for c in range(N)] for r in range(N)]

q = [(0,0)]
answer[0][0] = 0
# 다른 지점에서 벽을 더 적게 부수고 올 수 있기 때문에, 큐가 전부 빌때까지 bfs 탐색
while len(q) > 0:
    nq = []
    # 너비 하나 탐색
    for r,c in q:
	# 4방향에 대해서 인덱스 검사하고
        for nr, nc in ((r+1,c),(r-1,c),(r,c+1),(r,c-1)):
            if 0 <= nr < N and 0 <= nc < N:
		# 만약 더 적게 벽을 부수고 도달할 수 있다면 갱신 및 큐에 추가
                nb = answer[r][c] + room[nr][nc]
                if nb < answer[nr][nc]:
                    answer[nr][nc] = nb
                    nq.append((nr, nc))
    q = nq
# 탐색이 끝나면 마지막 위치에는 가장 적게 벽을 부수고 온 값이 들어있음
print(answer[N-1][N-1])
