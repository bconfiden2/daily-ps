# 뿌요들이 중력 영향 받는 효과는 행별로 일어남
def zipped(row):
    cnt = 11
    for i in range(11, -1, -1):
        if row[i] != '.':
            tmp = row[i]
            row[i] = '.'
            row[cnt] = tmp
            cnt -= 1

def dfs(graph, visited, r, c, ppy, arr):
    visited[r][c] = True
    arr.append((r, c))
    for nr,nc in ((r+1,c),(r-1,c),(r,c+1),(r,c-1)):
        if 0 <= nr < 6 and 0 <= nc < 12:
            if not visited[nr][nc] and graph[nr][nc] == ppy:
                dfs(graph, visited, nr, nc, ppy, arr)
    
def check(graph):
    visited = [[False for c in range(12)] for r in range(6)]
    bomb = False
    # 이번에 폭발이 일어나는지 검사
    for r in range(6):
        for c in range(12):
            # 폭발 가능한 위치들에 대해
            if graph[r][c] == '.' or visited[r][c]: continue
            arr = []
            dfs(graph, visited, r, c, graph[r][c], arr)
            if len(arr) >= 4:
                bomb = True
                for x,y in arr:
                    graph[x][y] = '.'
    # 이번 필드에서 폭발이 일어났을 경우
    if bomb:
        # 뿌요들 중력 영향 받게 한 뒤
        for row in graph:
            zipped(row)
        # 이번 연쇄 1 + 다음 연쇄 횟수를 반환
        return 1 + check(graph)
    # 이번 필드에서 폭발이 일어나지 않은 경우 연쇄 0 반환
    else:
        return 0

graph = [["." for c in range(12)] for r in range(6)]
for c in range(12):
    for r,v in enumerate(input()):
        graph[r][c] = v
print(check(graph))
