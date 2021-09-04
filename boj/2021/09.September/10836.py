import sys
M, N = map(int, input().split())
# sz는 문제에서 주어진 왼쪽아래부터 오른쪽위 방향의 애벌레 값들
sz = [1 for i in range(2*M-1)]

for line in sys.stdin:
    a,b,c = map(int, line.strip().split())
    # 각 애벌레 성장속도에 맞게 값 증가
    for i in range(a, a+b):
        sz[i] += 1
    for i in range(a+b, 2*M-1):
        sz[i] += 2

# 각 행의 첫번째 값은 첫열에서 가져오고, 나머지 열값들은 똑같음
tmp = " ".join(map(str, sz[M:]))
for i in range(M-1,-1,-1):
    print(sz[i], tmp)