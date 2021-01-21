import sys

N, Z, M = map(int, input().split())
obs = set(map(int, input().split()))

if Z == N:                                      # 모듈러 연산 기준으로 구하기 떄문에
    Z = 0                                       # Z 값이 N 값과 같다면 0 과 비교해준다.

for K in range(1, N):                           # K 를 1부터 N까지 돌려본다
    arr = [(1 + K * x) % N for x in range(N)]   # K 만큼 점프하면서 나오는 지점들을 순서대로 쌓음
    
    for val in arr:
        if val in obs:                          # 만약 장애물이 목표치보다 먼저 나온다면
            break                               # 바로 불가능 처리
        if val == Z:                            # 목표치가 장애물에 걸리지 않고 나올 경우
            print(K)                            # 프로그램 종료
            sys.exit()
