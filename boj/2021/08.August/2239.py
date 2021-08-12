import sys
sdk = [list(map(int, input())) for _ in range(9)]
# 스도쿠에서 i 번째 행에 들어있는 값들
rows = [set(sdk[i]) for i in range(9)]
# i 번째 열에 들어있는 값들
cols = [set([sdk[r][c] for r in range(9)]) for c in range(9)]
# i 번째 박스(왼쪽 상단부터 오른쪽 하단까지 슬라이딩) 들어있는 값들
boxs = [set([sdk[x//3*3+r][x%3*3+c] for r in range(3) for c in range(3)]) for x in range(9)]

# 백트래킹으로 다음 위치 계속 호출해나감
def fill(r, c):
    # 8,8(끝) 다음인 (9,0) 이 호출되었다면, 현재 스도쿠 상태 출력 후 종료
    if (r,c) == (9,0):
        for row in sdk:
            for col in row:
                print(col, end="")
            print()
        sys.exit()
    # 이번에 호출된 위치가 이미 값이 있는 곳이라면 그냥 다음 위치로 넘어감
    if sdk[r][c] != 0:
        fill((r + 1 if c==8 else r), (0 if c==8 else c+1))
    # 값을 채워야 하는 위치(0)일 경우는 가능한 값들 모두 탐색해봄
    else:
        # 1~9 까지 하나씩 넣어보는데
        for val in range(1, 10):
            x = 3*(r//3)+(c//3)
            # 만약 가로줄, 세로줄, 박스에 같은 값이 존재한다면 넣지 못함
            if val in rows[r] or val in cols[c] or val in boxs[x]:
                continue
            # 넣을 수 있는 값이라면 넣어주고
            sdk[r][c] = val
            rows[r].add(val)
            cols[c].add(val)
            boxs[x].add(val)
            # 다음 위치 재귀호출
            fill((r + 1 if c==8 else r), (0 if c==8 else c+1))
            # 재귀 쭉 돌다가 불가능해지면 여기로 넘어오게 되므로, 넣었던 값 빼주고, 반복문으로 다음 값 확인
            sdk[r][c] = 0
            rows[r].remove(val)
            cols[c].remove(val)
            boxs[x].remove(val)

fill(0, 0)