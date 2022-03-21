R, C = map(int, input().split())
graph = [list(input()) for _ in range(R)]
sr, sc = 0, 0
for r in range(R):
    for c in range(C):
        if graph[r][c] == '0':
            graph[r][c] = 11
            sr, sc = r, c
        elif graph[r][c] == '.':
            graph[r][c] = 11
        elif graph[r][c] == '1':
            graph[r][c] = 22
        elif 65 <= ord(graph[r][c]) <= 70:
            graph[r][c] = ord(graph[r][c]) - 15
        elif 97 <= ord(graph[r][c]) <= 102:
            graph[r][c] = ord(graph[r][c]) - 37
        elif graph[r][c] == '#':
            graph[r][c] = 99

# 특정 위치 r,c에 어떤 키 조합을 가지고 방문했는지 여부(키 조합 -> 000000~111111 까지 총 64개)
visited = [[[False for _ in range(C)] for _ in range(R)] for _ in range(64)]
cnt = 0
# 출발지점에서 아무런 키를 안가진 상태에서 시작
q = [(sr,sc,"0b000000")]
visited[0][sr][sc] = True
while len(q) > 0:
    nq = []
    for r, c, keys in q:
        if graph[r][c] == 22:
            print(cnt)
            exit()
        for nr, nc in ((r+1,c),(r-1,c),(r,c+1),(r,c-1)):
            if 0 <= nr < R and 0 <= nc < C and not visited[int(keys, 2)][nr][nc]:
                # 벽일 경우 스킵
                if graph[nr][nc] == 99: continue
                # 문인데 열쇠 없이 방문한 경우 스킵
                if 50 <= graph[nr][nc] <= 55 and keys[graph[nr][nc]-48] == '0': continue
                target = keys
                # 열쇠일 경우 현재 갖고 있는 열쇠 조합에 이번 열쇠 추가
                if 60 <= graph[nr][nc] <= 65:
                    tmp = graph[nr][nc]-58
                    target = target[:tmp] + "1" + target[tmp+1:]
                # 열쇠를 갖고 문을 들어온 경우, 열쇠일 경우, 그냥 빈공간일 경우 해당 위치를 다음 너비에 추가
                visited[int(target, 2)][nr][nc] = True
                nq.append((nr,nc,target))
    q = nq
    cnt += 1
print(-1)