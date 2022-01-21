import sys
R, C = map(int, input().split())
graph = [list(map(int, line.split())) for line in sys.stdin]
ans = ""
# R,C 둘중 하나라도 홀수일 경우 모든 점 포함 가능
if R%2 == 1:
    for l in range(R):
        ans += (('R'*(C-1) if l%2 == 0 else 'L'*(C-1)) + 'D')
elif C%2 == 1:
    for l in range(C):
        ans += (('D'*(R-1) if l%2 == 0 else 'U'*(R-1)) + 'R')
else:
    # 빠질 점 선택
    x, y = min((graph[r][c],(r,c)) for r in range(R) for c in range(C) if (r+c)%2 != 0)[1]
    # 빠지는 점 직전까지의 줄들(2줄 단위)
    ans += ('R'*(C-1) + 'D' + 'L'*(C-1) + 'D') * (x//2)
    # 빠질 점이 포함된 2줄
    ans += 'DRUR' * (y//2) + ('DR' if x%2==0 else 'RD') + ('RURD' * (((C-1)//2+1)-(y//2+1))) + 'D'
    # 나머지 줄들(2줄 단위)
    ans += ('L'*(C-1) + 'D' + 'R'*(C-1) + 'D') * (((R-1)//2+1)-(x//2+1))
print(ans[:-1])
