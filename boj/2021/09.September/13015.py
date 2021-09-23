N = int(input())
# 특정 줄의 별과 공백 갯수를 리스트로 주면 바꿔가면서 찍어줌
def printline(lst, star_start):
    is_star = star_start
    for num in lst:
        print(("*" if is_star else " ")*num, end="")
        is_star = not is_star
    print()

# 맨 윗줄
printline([N, 2*(N-2)+1, N], True)
# 위쪽 중간 부분
for i in range(N-3, -1, -1):
    printline([N-2-i, 1, N-2, 1, 2*i+1, 1, N-2, 1], False)
# 정중앙 부분
printline([N-1, 1, N-2, 1, N-2, 1], False)
# 아래쪽 중간 부분
for i in range(N-2):
    printline([N-2-i, 1, N-2, 1, 2*i+1, 1, N-2, 1], False)
# 맨 아랫줄
printline([N, 2*(N-2)+1, N], True)