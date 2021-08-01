N = int(input())
# 입력받은 용액들을 정렬해서 저장해놓음
liq = sorted(list(map(int, input().split())))
# 양쪽 끝점부터 0 에 가깝게 서서히 좁혀옴
ldx, rdx, lval, rval = 0, N-1, liq[0], liq[-1]
# 두 값의 차이가 가장 작을 때의 차이값
mini = abs(lval + rval)
# 왼쪽 포인터가 오른쪽 포인터를 넘어갈 때 까지 반복
while ldx < rdx:
    # 현재 차이값
    cur = liq[ldx] + liq[rdx]
    # 현재 차이값이 지금까지의 최소 차이값보다 작으면 갱신
    if abs(cur) < mini:
        mini = abs(cur)
        lval, rval = liq[ldx], liq[rdx]
    # 차이값이 0 이면 종료하고 출력(아무 쌍이나 상관 없음)
    if cur == 0:
        break
    # 두 차이가 0 보다 작으면 왼쪽 포인터를 땡겨서 값이 커지게
    elif cur < 0:
        ldx += 1
    # 0 보다 크면 오른쪽 포인터를 땡겨서 값이 작아지게
    elif cur > 0:
        rdx -= 1
print(lval, rval)