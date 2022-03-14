import sys
inp = lambda: sys.stdin.readline().split()
N = int(inp()[0])
graph = [[] for _ in range(N)]
for _ in range(N-1):
    p, q = map(lambda x:int(x)-1, inp())
    graph[p].append(q)
    graph[q].append(p)
target = list(map(lambda x:int(x)-1, inp()))
# 입력 순서가 문제처럼 1로 시작하지 않는 케이스도 들어옴
if target[0] != 0:
    print(0)
    exit()

visited = [False for _ in range(N)]
visited[0] = True
q = [0]
idx = 1
while len(q) > 0:
    nq = []
    for cur in q:
        cnt = 0
        # 이번 노드에서 연결되는 다음 너비의 노드들
        tmp = set()
        for nxt in graph[cur]:
            if not visited[nxt]:
                visited[nxt] = True
                tmp.add(nxt)
                cnt += 1
        # 입력받은 순서에서 해당 위치가 해당 노드들로만 이루어져있는지 확인
        tar = target[idx:idx+cnt]
        for v in tar:
            if v not in tmp:
                print(0)
                exit()
        idx += cnt
        # 해당 노드들을 다음 너비에 순서대로 추가
        for v in tar:
            nq.append(v)
    q = nq
print(1)