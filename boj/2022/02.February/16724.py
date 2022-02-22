import sys
sys.setrecursionlimit(1000000)
R, C = map(int, input().split())
graph = [list(v) for v in sys.stdin]
visited = [[0 for c in range(C)] for r in range(R)]
diri = {'D':(1,0),'U':(-1,0),'L':(0,-1),'R':(0,1)}

# 재귀적으로 하나씩 들어가며 연결되는 그룹끼리 이어줌
def dfs(r, c, area):
    visited[r][c] = area
    dt = diri[graph[r][c]]
    nr, nc = r + dt[0], c + dt[1]
    if 0 <= nr < R and 0 <= nc < C:
        # 다음 위치가 방문되지 않은 위치일 경우
        if visited[nr][nc] == 0:
            # 해당 위치로 들어가서 받아온 결과 그룹 = 내 그룹
            visited[r][c] = dfs(nr, nc, area)
            return visited[r][c]
        # 방문되었던 위치일 경우
        else:
            # 만약 내 그룹에서 이어져왔던 것일 경우, 그대로
            if visited[nr][nc] == area:
                return area
            # 기존에 다른 그룹으로 묶여있었다면, 해당 그룹 = 내 그룹
            else:
                visited[r][c] = visited[nr][nc]
                return visited[nr][nc]
    # 인덱스를 벗어나는 위치일 경우 내 그룹은 변경되지 않음
    return area

# 특정 위치부터 시작하여 연결되는 방향을 끝까지 따라가 그룹 형성
area = 1
for r in range(R):
    for c in range(C):
        if visited[r][c] == 0:
            if dfs(r, c, area) == area:
                area += 1
print(area-1)
