import sys
sys.setrecursionlimit(100000)
N, L, R = map(int, input().split())
A = [list(map(int, line.split())) for line in sys.stdin]
# 하, 상, 좌, 우
dirc = (1, -1, 0, 0)
# r,c 위치에서 어떤 방향으로 국경선이 열려있는지에 대한 정보
connected = {(r,c):[] for r in range(N) for c in range(N)}

# 국경선을 공유하는 두 나라 사이에, 조건에 의해 국경선을 열 것인지
def adj_open():
    flg = False
    for r in range(N):
        for c in range(N):
            # 매일마다 국경선은 초기화된 뒤
            connected[(r,c)] = []
            # 해당 나라에 인접한 4방향에 대하여 국경선을 열지 결정하여 저장
            for i in range(4):
                nr, nc = r + dirc[i], c + dirc[3-i]
                if 0 <= nr < N and 0 <= nc < N and L <= abs(A[r][c]-A[nr][nc]) <= R:
                    flg = True
                    connected[(r,c)].append(i)
    # 하나라도 국경이 열린다면, 인구 이동이 발생한다는 뜻
    return flg

# 같은 연합끼리 묶어서 (연합의 인구수) 와 (연합을 이루는 칸의 개수) 를 반환
def dfs(r, c, visited, tmp):
    visited[r][c] = True
    tmp.append((r,c))
    cumsum, cnt = 0, 0
    # r,c 나라에서 열려있는 국경선들에 대해서만 재귀적으로 탐색
    for i in connected[(r,c)]:
        nr, nc = r + dirc[i], c + dirc[3-i]
        if visited[nr][nc]: continue
        cs, ct = dfs(nr, nc, visited, tmp)
        cumsum += cs
        cnt += ct
    # r,c 위치에서 연결된 다른 나라들의 값을 모두 더한 뒤 자신의 값을 더해 반환
    return cumsum + A[r][c], cnt + 1

answer = 0
# 만약 연합이 발생하는 경우, 인구이동은 반드시 일어남
while adj_open():
    visited = [[False for c in range(N)] for r in range(N)]
    # 각 위치에서 dfs 를 돌려 연합들을 묶어준 뒤
    for r in range(N):
        for c in range(N):
            if not visited[r][c]:
                tmp = []
                cumsum, cnt = dfs(r, c, visited, tmp)
                # 해당 연합들에게 알맞은 인구수 분배
                for i,j in tmp:
                    A[i][j] = cumsum // cnt
    answer += 1
print(answer)
    