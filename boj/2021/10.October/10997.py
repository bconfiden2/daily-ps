n = int(input())
if n==1:
    print("*")
else:
    c1, c2 = "* ", " *"
    # 윗부분은 우선 아랫부분과 동일하지만, 각 줄마다 공백 혹은 별표가 추가된 형식
    for i in range(1, 2*n):
        tmp = list(c1*(i//2) + ("*" if i%2==1 else " ")*(4*n-3-4*(i//2)) + c2*(i//2))
        if i > 1:
            tmp[4*n-2-i] = "*" if i%2==1 else " " 
        print("".join(tmp).strip())
    # 위아래를 나누는 정중앙 라인
    print((c1 * (2*n-1)).strip())
    # 아랫부분 출력
    for i in range(2*n-1, 0, -1):
        print((c1*(i//2) + ("*" if i%2==1 else " ")*(4*n-3-4*(i//2)) + c2*(i//2)).strip())