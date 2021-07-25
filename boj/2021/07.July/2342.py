arr = list(map(int, input().split()))[:-1]

# DP 배열은 [i번째][왼발][오른발] 일 때 드는 힘의 최소 크기
dp = [[[[] for c in range(5)] for r in range(5)] for i in range(len(arr)+1)]

# 커맨드 상 존재할 수 없는 위치는 -1 로 초기화
for lft in range(5):
        for rgt in range(5):
            dp[0][lft][rgt] = -1
# 0번째 커맨드(시작 전)에서는 시작위치가 왼발 0 오른발 0 이므로 드는 힘을 0 으로 초기화
dp[0][0][0] = 0

# 발의 이전 위치와 움직일 위치가 주어졌을 때 추가되는 힘을 구해주는 함수
def p(pair):
    if pair[0] == pair[1]:
        return 1
    if 0 in pair:
        return 2
    if pair in ((1,3),(3,1),(2,4),(4,2)):
        return 4
    else:
        return 3

# 각 커맨드마다 가능한 발의 위치쌍에 대해 최소값 검사
for idx, cur in enumerate(arr):
    for lft in range(5):
        for rgt in range(5):
            # 불가능한 발들은 확인하지 않음
            if dp[idx][lft][rgt] == -1:
                continue
            # 왼쪽 발을 옮겼을 때, 오른발과 겹치지 않을 경우 다음 위치에 후보로써 추가해놓음
            if cur != rgt:
                dp[idx+1][cur][rgt].append(dp[idx][lft][rgt] + p((lft, cur)))
            # 오른쪽 발을 옮길 때
            if cur != lft:
                dp[idx+1][lft][cur].append(dp[idx][lft][rgt] + p((rgt, cur)))
    # 한번 돌고나면, 각 위치쌍마다 왼쪽이든 오른쪽이든 발을 옮기고 난 뒤 드는 힘들이 모여있으므로, 그 중 최소값을 선택
    for lft in range(5):
        for rgt in range(5):
            dp[idx+1][lft][rgt] = -1 if len(dp[idx+1][lft][rgt]) == 0 else min(dp[idx+1][lft][rgt])

print(min(dp[len(arr)][r][c] for r in range(5) for c in range(5) if dp[len(arr)][r][c] != -1))