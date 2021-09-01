N = int(input())
pn = []
visited = [False] * (N+1)
# 에라토스테네스의 체로 N 이하의 소수들을 pn 에 저장
for i in range(2, N+1):
    if visited[i]:
        continue
    pn.append(i)
    tmp = i * 2
    while tmp <= N:
        visited[tmp] = True
        tmp += i

# 투 포인터로 합이 N 이 되는 구간들을 전부 탐색
answer = 0
if len(pn) > 0:
    ldx, rdx = 0, 1
    tmp = pn[ldx]
    while ldx < rdx:
        if tmp <= N:
            if tmp == N:
                answer += 1
            if rdx == len(pn):
                break
            tmp += pn[rdx]
            rdx += 1
        else:
            tmp -= pn[ldx]
            ldx += 1
print(answer)