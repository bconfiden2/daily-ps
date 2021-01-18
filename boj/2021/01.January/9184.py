w = [[[1 for a in range(21)] for b in range(21)] for c in range(21)]    # 계산된 w값들. 재사용하여 재귀를 막음

def pre_calculate(a, b, c):                 # 주어진 알고리즘 그대로
    if a < b and b < c:
        w[a][b][c] = w[a][b][c-1] + w[a][b-1][c-1] - w[a][b-1][c]
    else:
        w[a][b][c] = w[a-1][b][c] + w[a-1][b-1][c] + w[a-1][b][c-1] - w[a-1][b-1][c-1]

for a in range(1, 21):
    for b in range(1, 21):
        for c in range(1, 21):
            pre_calculate(a, b, c)          # w 함수 재귀호출을 미리 계산해놓음

while True:
    a, b, c = map(int, input().split())
    if a == -1 and b == -1 and c == -1:     # 종료 값인지 검사
        break
    answer = 0
    if a <= 0 or b <= 0 or c <= 0:          # 하나라도 0 이하가 있으면 무조건 1
        answer = 1
    elif a > 20 or b > 20 or c > 20:        # 전부 다 20 초과일 경우 20,20,20 의 값 반환
        answer = w[20][20][20]
    else:
        answer = w[a][b][c]                 # 그 외엔, 미리 계산해둔 w 출력값 반환
    print(f"w({a}, {b}, {c}) =", answer)