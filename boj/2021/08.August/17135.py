from queue import Queue

N, M, D = map(int, input().split())
grid_origin = [list(map(int, input().split())) for n in range(N)]
dirR, dirC = (0,-1,0), (-1,0,1)

# 궁수 한명의 현재 위치가 주어졌을 때, 자기가 쏠 적의 위치 반환 
def bfs(sr, sc, grid):
    q = Queue()
    # 궁수 현재 위치에서 바로 앞 위치부터 탐색 시작
    q.put((sr-1,sc))
    # 중복 탐색 제거를 위한 배열
    visited = [[False for c in range(M)] for r in range(sr)]
    visited[sr-1][sc] = True
    dist = 0

    # 사정거리 안에 있는 모든 위치를 검사
    while not q.empty() and dist != D:
        # 현재 사정거리의 위치들을 검사해서
        for _ in range(q.qsize()):
            r, c = q.get()
            # 만약 적이 있다면 해당 위치 반환(큐에 왼쪽-위쪽-오른쪽 순으로 넣기 때문에 가장 먼저 나온 적이 가장 왼쪽 적)
            if grid[r][c] == 1:
                return (r,c)
            # 적이 없었다면, 현재 위치의 왼쪽-위쪽-오른쪽 방향으로 다음 사정거리에 넣어줌
            for i in range(3):
                nr, nc = r + dirR[i], c + dirC[i]
                # 인덱스 검사할 때는, 궁수의 위치보다 높은 곳에 있어야 함
                if 0 <= nr and nr < sr and 0 <= nc and nc < M:
                    if not visited[nr][nc]:
                        visited[nr][nc] = True
                        q.put((nr, nc))
        # 현재 사정거리의 위치를 검사했기 때문에 1 올려서 다음 사정거리 위치들 검사
        dist += 1
    # 적을 발견 못했다면 -1 반환
    return -1

# 궁수들의 위치가 주어졌을 때 적을 얼마나 없앨 수 있는지 검사해주는 함수
def check(*positions):
    # 적이 쓰러진 횟수 cnt
    cnt = 0
    # 기존 그리드에 영향 가지 않게 복사해서 사용
    grid = [[r for r in row] for row in grid_origin]
    # 궁수들(성)이 위로 한칸씩 움직인다고 생각하고
    for arc_r in range(N,0,-1):
        # 각 궁수들이 bfs 를 통해 자기가 쏠 적을 알려주면
        target = [v for v in set(bfs(arc_r, p, grid) for p in positions) if v != -1]
        # 해당 적들을 없애고
        for r,c in target:
            grid[r][c] = 0
        # 없앤 적의 숫자를 셈
        cnt += len(target)
    return cnt

# 궁수 3명이 설 수 있는 모든 경우의 수에 대해서 각각 검사해보고 그 중 최댓값 출력
print(max(check(a,b,c) for a in range(0, M-2) for b in range(a+1, M-1) for c in range(b+1, M)))