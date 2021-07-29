C = int(input())
answer = 0

# idx 번째 포지션에 적합한 선수를 고르고, 다음 포지션을 재귀적으로 탐색
def select(idx, mat, pos, visit, value):
    # 모든 선수들을 다 고를 수 있는 경우에만 최대값 갱신
    if idx == 11:
        global answer
        if value > answer:
            answer = value
        return
    # 해당 포지션에 적합한 모든 선수들을 탐색하는데
    for candidate in pos[idx]:
        # 이미 앞에서 다른 포지션에 선택된 선수는 제외시키고
        if visit[candidate]: continue
        visit[candidate] = True
        # value 에 해당 선수의 해당 포지션 능력치를 더해주면서 다음 포지션 재귀호출
        select(idx+1, mat, pos, visit, value+mat[candidate][idx])
        visit[candidate] = False

# 각 테스트케이스에 대해
for _ in range(C):
    mat = [list(map(int, input().split())) for r in range(11)]
    # 각 포지션에 적합한 선수들의 목록을 관리(0번 포지션에 적합한 선수들, ...)
    pos = [[] for i in range(11)]
    for i, player in enumerate(mat):
        for idx, val in enumerate(player):
            if val != 0:
                pos[idx].append(i)
    # 포지션을 차례대로 선택해나가는 백트래킹 과정
    select(0, mat, pos, [False for i in range(11)], 0)
    print(answer)
    # 테케가 여러개이기 때문에 정답 값 초기화 필요
    answer = 0