R, C = map(int, input().split())
# cs[r][c] = (1,1)~(r,c) 크기 직사각형의 합
cs = [[0 for c in range(C+1)] for r in range(R+1)]
for r in range(1, R+1):
    line = input()
    for c in range(1, C+1):
        cs[r][c] = int(line[c-1]) + cs[r-1][c] + cs[r][c-1] - cs[r-1][c-1]

# 세로 가로 1줄씩 그어 3개로 나눈 경우 -> 4가지 존재
answer = 0
for r in range(1, R):
    for c in range(1, C):
        t1 = (cs[r][c]) * (cs[r][C]-cs[r][c]) * (cs[R][C]-cs[r][C]) # ㅗ
        t2 = (cs[r][c]) * (cs[R][c]-cs[r][c]) * (cs[R][C]-cs[R][c]) # ㅓ
        t3 = (cs[r][C]) * (cs[R][c]-cs[r][c]) * (cs[R][C]-cs[r][C]-cs[R][c]+cs[r][c]) # ㅜ 
        t4 = (cs[R][c]) * (cs[r][C]-cs[r][c]) * (cs[R][C]-cs[R][c]-cs[r][C]+cs[r][c]) # ㅏ
        answer = max(answer, t1, t2, t3, t4)
# 세로로만 3줄, 가로로만 3줄로 나눈 경우 확인
t5 = max((cs[r1][C]) * (cs[r2][C]-cs[r1][C]) * (cs[R][C]-cs[r2][C]) for r1 in range(R) for r2 in range(r1, R))
t6 = max((cs[R][c1]) * (cs[R][c2]-cs[R][c1]) * (cs[R][C]-cs[R][c2]) for c1 in range(C) for c2 in range(c1, C))
print(max(answer, t5, t6))