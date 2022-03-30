import sys
N, M = map(int, input().split())
edges = [tuple(map(int, line.split())) for line in sys.stdin]
dist = [10**10 for _ in range(N+1)]
dist[1] = 0

# 벨만 포드
for n in range(1, N+1):
    for p, q, w in edges:
        if dist[p] != 10**10 and dist[q] > dist[p] + w:
            dist[q] = dist[p] + w
            # 음수 싸이클이 발생하는 경우
            if n == N:
                print(-1)
                exit()
print("\n".join(map(lambda x: "-1" if x==10**10 else str(x), dist[2:])))