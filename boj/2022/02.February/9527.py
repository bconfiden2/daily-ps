# 이진탐색으로 절반씩 나눠가면서 목표값 이하 숫자의 1의 개수를 반환
def fd(d, val, pf):
    if d==2:
        return pf+1 if val==0 else 2*pf+3
    if val < 2**(d-2):
        return fd(d-1, val, pf)
    else:
        return pf*(2**(d-2)) + num[d-1] + fd(d-1, val-2**(d-2), pf+1)

A, B = map(int, input().split())
a, b = len(bin(A))-2, len(bin(B))-2
ans, num = (1 if a==1 else 0), [0, 1]
# 이진수 자릿수가 a+1 ~ b-1 인 수들은 모두 그대로 사용 가능
for i in range(2, b):
    num.append(2*num[i-1]+2**(i-2))
    if i >= a:
        ans += num[i]
# 자릿수가 b인 수들 중 B 이하인 수들의 1의 개수를 더해주고, 자릿수가 a인 수들 중 A 미만인 수들의 1의 개수는 빼줌
ans += (fd(b, B-2**(b-1), 0) if B!= 1 else 0) - (fd(a, A-2**(a-1)-1, 0) if A!=2**(a-1) else 0)
print(ans)