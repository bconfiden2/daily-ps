import sys
N, M = map(int, input().split())
com = [[] for _ in range(N)]
for line in sys.stdin:
    A, B = map(int, line.split())
    com[B-1].append(A-1)

# 해당 노드와 연결되어있는 모든 노드들의 개수를 bfs 로 반환
def bfs(n):
    visited = [False for _ in range(N)]
    visited[n] = True
    q = [n]
    cnt = 0
    while len(q) > 0:
        nq = []
        for cur in q:
            cnt += 1
            for nxt in com[cur]:
                if not visited[nxt]:
                    visited[nxt] = True
                    nq.append(nxt)
        q = nq
    return cnt

# 모든 노드에서 bfs 를 통해 연결되는 노드 개수 검사
hack = [bfs(i) for i in range(N)]
maxi = max(hack)
# 최대값을 갖는 여러 노드들 한줄에 출력
print(" ".join((str(idx+1) for idx, val in enumerate(hack) if val == maxi)))