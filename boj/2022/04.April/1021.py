def left(v, dq):
    cnt = 0
    while dq[0] != v:
        dq.appendleft(dq.pop())
        cnt += 1
    dq.popleft()
    return cnt

def right(v, dq):
    cnt = 0
    while dq[0] != v:
        dq.append(dq.popleft())
        cnt += 1
    dq.popleft()
    return cnt

from collections import deque
N, M = map(int, input().split())
dq = deque((i for i in range(1, N+1)))
ans = 0
for v in map(int, input().split()):
    l, r = left(v, dq.copy()), right(v, dq.copy())
    if l <= r:
        ans += l
        left(v, dq)
    else:
        ans += r
        right(v, dq)
print(ans)