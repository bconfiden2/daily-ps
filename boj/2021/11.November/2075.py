N, ans = int(input()), []
# 매번 들어오는 수들에 대해서, 내림차순으로 상위 N 개만 메모리에 유지
for _ in range(N):
    ans = sorted(ans + list(map(int, input().split())), reverse=True)[:N]
print(ans[-1])