C, R = map(int, input().split())
graph = [list(map(int, input().split())) for _ in range(R)]
for r in range(R):
    for c in range(C):
        tmp = graph[r][c]
        # 서 북 동 남
        graph[r][c] = [0 if (tmp & i) > 0 else 1 for i in (1,2,4,8)]

dr = (0,-1,0,1)
dc = (-1,0,1,0)

# 방의 개수와 가장 넓은 방의 넓이를 구하기 위한 dfs
# 구하는 동시에 각 방의 영역을 같은 값으로 표시해놓음
def dfs(r, c, visited, area, my):
    ret = 1
    area[r][c] = my
    visited[r][c] = True
    for i in range(4):
        if graph[r][c][i] > 0:
            nr = r + dr[i]
            nc = c + dc[i]
            if 0 <= nr < R and 0 <= nc < C and not visited[nr][nc]:
                ret += dfs(nr, nc, visited, area, my)
    return ret

# cnt : 각 방번호별 크기를 담을 딕셔너리
cnt = {}
# area : 각 방을 방번호별로 나눠 저장하는 배열
area = [[0 for _ in range(C)] for _ in range(R)]
num1 = num2 = num3 = 0
visited = [[False for _ in range(C)] for _ in range(R)]
for r in range(R):
    for c in range(C):
        if not visited[r][c]:
            num1 += 1
            tmp = dfs(r, c, visited, area, num1)
            num2 = max(num2, tmp)
            cnt[num1] = tmp

# 하나의 벽을 제거한다 = 인접한 두 방이 붙는다
# 어떤 두 방이 인접한지, 가능한 모든 후보들을 탐색하는 dfs
def boundary(r, c, visited, candi):
    visited[r][c] = True
    for i in range(4):
        nr = r + dr[i]
        nc = c + dc[i]
        if 0 <= nr < R and 0 <= nc < C and not visited[nr][nc]:
            # 만약 방으로 연결되어있으면 계속 방문
            if graph[r][c][i] > 0:
                boundary(nr, nc, visited, candi)
            # 인접해있지만 벽으로 막힌 경우, 방문처리는 하지 않지만 인접한 방 후보에 추가
            else:
                candi.add((area[r][c], area[nr][nc]))

candi = set()
visited = [[False for _ in range(C)] for _ in range(R)]
for r in range(R):
    for c in range(C):
        if not visited[r][c]:
            boundary(r, c, visited, candi)
# 모든 인접해있는 방들 중 어떤 두개를 합쳐야 크기가 가장 넓어질지
num3 = max(cnt[a] + cnt[b] for a, b in candi if a!=b)

print(num1)
print(num2)
print(num3)