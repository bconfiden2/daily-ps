N, B = map(int, input().split())
mat = [list(map(int, input().split())) for i in range(N)]
answer = [[1 if i==j else 0 for j in range(N)] for i in range(N)]   # 업데이트 될 정답행렬, I 로 시작

def matmul(a, b):               # 행렬곱 함수, 모듈러 연산이 적용돼있음
    return [[sum(r) % 1000 for r in zip(*[[(arow[i] * e) % 1000 for e in b[i]] for i in range(N)])] for arow in a]

for flag in map(int, str(bin(B))[-1:1:-1]):     # B 를 2진수로 바꿔서 mat 을 제곱해주며 필요한 승수마다 answer 에 곱해줌
    if flag:
        answer = matmul(answer, mat)
    mat = matmul(mat, mat)                      # mat 은 계속 제곱됨

for row in answer:
    print(*row)