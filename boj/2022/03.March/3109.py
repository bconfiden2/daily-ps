# 파이프를 가능한 위쪽으로 땡겨서 연결
def dfs(r, c):
    # 재귀로 들어오면서 결국 마지막 열까지 도달하면 파이프 형성
    if c == C-1:
        return True
    # 위, 중간, 아래 순으로 다음 열 탐색
    for nr, nc in ((r-1,c+1),(r,c+1),(r+1,c+1)):
        if 0 <= nr < R and graph[nr][nc] != 'x':
            graph[nr][nc] = 'x'
            # 다음 위치들 중 하나라도 파이프 형성된 곳이 있으면 True
            if dfs(nr, nc):
                return True
    # 어떤 위치에서든 파이프 형성 안될 경우 False
    return False

import sys
R, C = map(int, input().split())
graph = [list(l.strip()) for l in sys.stdin]
# 모든 시작위치별로 검사해서 형성되는 파이프 개수 확인
print(sum(int(dfs(r, 0)) for r in range(R)))
