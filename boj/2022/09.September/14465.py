import sys
N, K, B = map(int, input().split())
state = [0 for _ in range(N)]
for v in map(lambda x: int(x)-1, sys.stdin):
    state[v] = 1

ans = cnt = sum(state[:K])
for i in range(N-K):
    cnt += state[i+K] - state[i]
    ans = min(ans, cnt)
print(ans)
