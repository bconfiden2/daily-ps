MAX = 1000000007
graphs = [[[0 for _ in range(8)] for _ in range(8)] for _ in range(32)]
graphs[1] = [
    [0, 1, 1, 0, 0, 0, 0, 0],
    [1, 0, 1, 1, 0, 0, 0, 0],
    [1, 1, 0, 1, 1, 0, 0, 0],
    [0, 1, 1, 0, 1, 1, 0, 0],
    [0, 0, 1, 1, 0, 1, 1, 0],
    [0, 0, 0, 1, 1, 0, 0, 1],
    [0, 0, 0, 0, 1, 0, 0, 1],
    [0, 0, 0, 0, 0, 1, 1, 0]
]

# 두개의 행렬을 곱해서 result 에 결과행렬을 넣어줌
def matmul(g1, g2, result):
    for r in range(8):
        for c in range(8):
            result[r][c] = sum((g1[r][x]%MAX) * (g2[x][c]%MAX) for x in range(8)) % MAX

# 2의 1 ~ 31승에 해당하는 행렬들을 미리 만들어놓은 뒤
for i in range(1, 31):
    matmul(graphs[i], graphs[i], graphs[i+1])

# 입력값을 이진수로 변환하여, 원하는 제곱수만큼 곱해진 행렬을 만들 때 미리 구해놨던 행렬들을 사용
answer = [[1 if r==c else 0 for c in range(8)] for r in range(8)]
for i, v in enumerate(bin(int(input()))[-1:1:-1]):
    if v == '1':
        tmp = [[0 for _ in range(8)] for _ in range(8)]
        matmul(graphs[i+1], answer, tmp)
        answer = tmp

# 결과적으로 D 번을 거쳐 자기 자신으로 돌아오는 경우의 수가 담겨있음
print(answer[0][0])