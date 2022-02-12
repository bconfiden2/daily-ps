from itertools import product
N = int(input())
graph = [list(map(int, input().split())) for i in range(N)]

# 하나의 행을 2048 규칙에 맞게 압축시킴
def zipped(row):
    bv, bdx = 0, 0
    for i in range(N):
        if row[i] != 0:
            if bv == row[i]:
                row[i] = 0
                row[bdx] = bv * 2
                bv, bdx = 0, 0
            else:
                bv, bdx = row[i], i
    cnt = 0
    for i in range(N):
        if row[i] != 0:
            tmp = row[i]
            row[i] = 0
            row[cnt] = tmp
            cnt += 1
    return row

# 방향에 따라 압축시켜야 할 라인을 행으로 바꿔서 압축시켜서 가져옴
def go(G, flg):
    for i in range(N):
        if flg == 0:
            tmp = zipped([G[r][i] for r in range(N)])
            for r in range(N):
                G[r][i] = tmp[r]
        elif flg == 1:
            tmp = zipped([G[r][i] for r in range(N-1, -1, -1)])
            for r in range(N-1, -1, -1):
                G[r][i] = tmp[r]
        elif flg == 2:
            G[i] = zipped(G[i])
        elif flg == 3:
            G[i] = zipped(G[i][::-1])[::-1]

def roll(lst, graph):
    for v in lst:
        go(graph, v)
    return max(v for row in graph for v in row)
print(max(roll(x, [[v for v in row] for row in graph]) for x in product(range(4), repeat=5)))