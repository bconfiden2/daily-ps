import sys
N, M = map(int, input().split())
ban = set(i for i in map(int, sys.stdin))
table = [[-1 for _ in range(143)] for n in range(N+1)]
table[1][0] = 0

def check(jmp, cur, cnt):
    if jmp <= 0 or cur+jmp > N or cur+jmp in ban:
        return
    table[cur+jmp][jmp] = cnt + 1

for i in range(1, N):
    for idx, val in enumerate(table[i]):
        if val != -1:
            check(idx-1, i, val)
            check(idx, i, val)
            check(idx+1, i, val)

ans = [i for i in table[N] if i != -1]
print(-1 if len(ans) == 0 else min(ans))