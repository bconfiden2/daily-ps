# 소수끼리 연결된 그래프에서 bfs 통해 최소 회수 구하기
def bfs(a, b):
    visited = [False for _ in range(10000)]
    visited[a] = True
    q = [a]
    cnt = 0
    while len(q) > 0:
        nq = []
        for cur in q:
            if cur == b:
                return str(cnt)
            for nxt in graph[cur]:
                if not visited[nxt]:
                    visited[nxt] = True
                    nq.append(nxt)
        q = nq
        cnt += 1
    return "Impossible"
    
import sys
# 에라토스테네스의 체로 10000 미만 소수들 구해놓음
ec = [False for _ in range(10000)]
for x in range(2, 5000):
    tmp = x * 2
    while tmp < 10000:
        if not ec[tmp]: ec[tmp] = True
        tmp += x

# 한 자리만 바꿔서 만들어지는 소수끼리 연결한 그래프
graph = [[] for _ in range(10000)]
for i in range(1000, 10000):
    # 각 자리별로 0~9 까지 대입해보면서
    for digit in range(4):
        x = list(str(i))
        for val in range(10):
            if digit == 0 and val == 0: continue
            x[digit] = str(val)
            tmp = int("".join(x))
            # 바뀐 수가 소수일 경우, 서로 연결시킴
            if not ec[tmp]:
                graph[i].append(tmp)

input()
for l in sys.stdin:
    a, b = map(int, l.split())
    print(bfs(a, b))
