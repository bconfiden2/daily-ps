testcases = int(input())

for t in range(testcases) :
    flies = []
    ans = 0
    n, m = map(int, input().split())
    for r in range(n) :
        flies.append(list(map(int, input().split())))   # 파리 갯수 정보(2차원 리스트)
    for r in range(n - m + 1) :
        for c in range(n - m + 1) :                     # 영역들 완전탐색 (인덱스 고려)
            temp = 0
            for tr in range(m) :                            # 파리채 영역
                for tc in range(m) :
                    temp += flies[r+tr][c+tc]
            if temp > ans :
                ans = temp
    print("#{} {}".format(t+1, ans))