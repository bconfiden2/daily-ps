def gcd(m,n):
    while n != 0:
        t = m%n
        (m,n) = (n,t)
    return m

import sys
N = int(input())
ds = {(0,1):0, (1,0):0}
for line in sys.stdin:
    a, b, c = map(int, line.split())
    # 계수 a,b 둘 중에 하나가 0일때는 최대공약수로 나누지 않고 따로 묶어서 저장
    if a==0:
        ds[(0,1)] += 1
    elif b==0:
        ds[(1,0)] += 1
    # 최대공약수로 나눠서 기약분수 형태로 저장
    else:
        m = gcd(abs(a), abs(b)) * (-1 if a<0 else 1)    
        ds[(a//m, b//m)] = ds.get((a//m, b//m), 0) + 1

# 묶인 그룹별로 다른 그룹과 쌍을 매칭시킴(그룹 내의 인원 수 반영)
cumsum = 0
answer = 0
for key, value in ds.items():
    cumsum += value
    answer += value * (N-cumsum)
print(answer)