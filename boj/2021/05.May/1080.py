N, M = map(int, input().split())

A = [list(map(int, input())) for i in range(N)]
B = [list(map(int, input())) for i in range(N)]

def check():                            # A 와 B 두 행렬이 같은지 검사하는 함수
    for i in range(N):
        for j in range(M):
            if A[i][j] != B[i][j]:
                return False
    return True

def push(r, c):                         # 특정 위치에서 3x3 을 뒤집어주는 함수
    for i in range(3):
        for j in range(3):
            A[r+i][c+j] = int(not A[r+i][c+j])

if N < 3 or M < 3:                      # 애초에 뒤집을 수 없는 행렬이라면 검사하고 종료
    print(0 if check() else -1)
else:
    cnt = 0
    for i in range(N-2):                # [0][0] 부터 [N-3][M-3] 행렬을 검사 
        for j in range(M-2):
            if A[i][j] != B[i][j]:      # 만약 값이 다르다면
                push(i, j)              # 헤딩 위치에서 뒤집어주고
                cnt += 1                # 처리
                if check():
                    print(cnt)
    if not check():                     # 전체 검사 후에도 행렬이 다르다면 -1 출력
        print(-1)