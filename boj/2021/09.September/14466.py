import sys
N, K, R = map(int, input().split())
# graph 값이 0이면 빈 공간, 1이면 소, -1이면 dfs 방문이라는 표시
graph = [[0 for c in range(N+1)] for r in range(N+1)]
# walls 는 해당 지점의 어느 방향들로 길이 연결되어있는지 관리
walls = [[[] for c in range(N+1)] for r in range(N+1)]
# 0(상) 1(우) 2(하) 3(좌)
dire = (-1, 0, 1, 0)

for _ in range(R):
    r1,c1,r2,c2 = map(int, sys.stdin.readline().split())
    walls[r1][c1].append((r2-r1, c2-c1))
    walls[r2][c2].append((r1-r2, c1-c2))
for _ in range(K):
    r,c = map(int, input().split())
    graph[r][c] = 1

# 길로 나뉘어진 영역들을 탐색하며 해당 영역에 소가 몇마리 있는지 카운트
def dfs(r, c):
    ret = graph[r][c]
    graph[r][c] = -1
    tmp = 0
    for i in range(4):
        # 길로 나뉘어있으면 스킵
        if (dire[i], dire[3-i]) in walls[r][c]: continue
        nr, nc = r+dire[i], c+dire[3-i]
        # 인덱스 검사하고 연결된 영역들에 재귀적으로 dfs 호출
        if 1 <= nr <= N and 1 <= nc <= N and graph[nr][nc] != -1:
            tmp += dfs(nr, nc)
    # 현재 영역에 있는 소 + 재귀적으로 아래 영역들에 존재하는 소 반환
    return ret + tmp

# dfs 탐색을 통해 소들을 그룹별로 나누고, 해당 그룹에 몇마리가 있는지를 group 에 저장
group = []
for r in range(1, N+1):
    for c in range(1, N+1):
        if graph[r][c] != -1:
            group.append(dfs(r, c))
# 그룹별로 나뉘어있는 소들을 가지고 만들 수 있는 쌍의 개수 셈
cumsum = 0
answer = 0
for cur in group:
    cumsum += cur
    answer += cur * (K-cumsum)
print(answer)