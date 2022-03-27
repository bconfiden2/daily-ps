N = int(input())
M = int(input())
graph = [[] for _ in range(N)]
degree = [0 for _ in range(N)]
count = [0 for _ in range(N)]

for _ in range(M):
    X, Y, K = map(int, input().split())
    X, Y = X-1, Y-1
    graph[X].append((Y, K))
    degree[Y] += 1
# 역방향으로 연결했기 때문에, 연결된 노드가 없는 노드들이 기본 부품
answer = [i for i,v in enumerate(graph) if len(v)==0]

# 완제품부터 기본부품까지 역순으로 탐색
q = [N-1]
count[N-1] = 1
while len(q) > 0:
    nq = []
    for cur in q:
        for nxt, v in graph[cur]:
            # 각 중간제품들에 자신을 만들기 위한 개수만큼 곱
            count[nxt] += count[cur] * v
            degree[nxt] -= 1
            if degree[nxt] == 0:
                nq.append(nxt)
    q = nq

# 기본부품별로 해당 부품의 필요 개수 출력
for v in answer:
    print(v+1, count[v])