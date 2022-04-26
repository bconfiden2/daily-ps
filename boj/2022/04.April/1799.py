# 45도 돌린 그래프의 r,c 를, 원래 그래프의 위치로 변환
def r2o(r, c):
    a = (r-c+N-1) / 2
    x = int(a)
    return (x, r - x) if x == a and (0 <= x < N and 0 <= r-x < N) else (-1, -1)

# 기존 그래프를 45도 돌린 뒤 N-Queen 처럼 백트래킹
def bt(x):
    # 모든 행을 검사하면 최댓값 갱신
    if x == 2*N-1:
        global ans
        ans = max(ans, sum(1 for i in arr if i != -1))
        return
    called = False
    # 각 행마다 모든 열에 대해서 검사
    for i in range(2*N-1):
        r, c = r2o(x, i)
        # 유효한 위치이고, 비숍을 놓을 수 있으며, 비숍끼리 겹치지 않을 경우
        if r != -1 and graph[r][c] == 1 and i not in arr:
            called = True
            arr[x] = i
            bt(x + 1)
            arr[x] = -1
    # 이번 행에 넣어줄 수 있는 비숍이 없더라도 일단 끝까지 탐색시킴
    if not called:
        bt(x + 1)

N = int(input())
graph = [list(map(int, input().split())) for _ in range(N)]
arr = [-1 for _ in range(2*N-1)]
ans = 0
bt(0)
print(ans)