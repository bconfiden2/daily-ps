import sys
N, M = map(int, input().split())
graph = [[] for _ in range(N)]
degree = [0 for _ in range(N)]
# 키를 비교한 방향으로 그래프 연결
for line in sys.stdin:
    a, b = map(lambda x: int(x)-1, line.split())
    graph[b].append(a)
    degree[a] += 1
# 위상정렬을 통해 뒤에 서야하는 사람부터 줄세우기
answer = []
q = [i for i,v in enumerate(degree) if v==0]
while len(q) > 0:
    nq = []
    for cur in q:
        answer.append(cur+1)
        for nxt in graph[cur]:
            degree[nxt] -= 1
            if degree[nxt] == 0:
                nq.append(nxt)
    q = nq
print(" ".join(map(str, answer[::-1])))