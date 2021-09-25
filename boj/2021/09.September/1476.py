E, S, M = map(int, input().split())
answer = e = s = m = 1
# 날짜가 같아질때까지 계속 돌림
while e!=E or s!=S or m!=M:
    e, s, m = (e%15)+1, (s%28)+1, (m%19)+1
    answer += 1
print(answer)