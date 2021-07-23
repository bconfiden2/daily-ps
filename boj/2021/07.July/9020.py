import sys

rn = [True for i in range(10001)]
prime = []
pt = [(0,0) for i in range(20000)]

# 에라토스테네스의 체로 10000 이하의 모든 소수들 구함
for i in range(2, 10001):
    if rn[i]:
        prime.append(i)
        tmp = i + i
        while tmp <= 10000:
            rn[tmp] = False
            tmp += i

# 모든 조합을 살펴보며 골드바흐 파티션을 구함
for i1 in range(len(prime)):
    for i2 in range(i1, len(prime)):
        # 첫번째 수와 두번째 수를 뽑아 가능한 값들에 해당 쌍을 저장
        # 여러 쌍이 있을 경우 자연스럽게 뒤쪽에서 두 값이 더 가까운 쌍으로 갱신됨
        pt[prime[i1] + prime[i2]] = (prime[i1], prime[i2])

# 골드바흐 파티션을 메모이제이션 해놨으므로 답 출력
input()
for line in sys.stdin:
    line = int(line.strip())
    print(pt[line][0], pt[line][1])
