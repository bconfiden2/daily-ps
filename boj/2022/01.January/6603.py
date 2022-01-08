from itertools import combinations

# flg 는 테스트케이스 간 공백 출력을 위한 플래그
flg = False
while True:
    cur = list(map(int, input().split()))
    if cur[0] == 0:
        break
    elif flg:
        print()
    # 테스트케이스별로 제공되는 라이브러리 사용하여 모든 조합 출력
    for row in combinations(cur[1:], 6):
        print(" ".join(map(str, row)))
    flg = True