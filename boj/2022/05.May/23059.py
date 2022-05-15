import sys
input = sys.stdin.readline

N = int(input())
item_to_node = {}
node_to_item = {}
graph, degree = [], []

# 입력받는 아이템 이름을 가지고 그래프 및 딕셔너리 형성
icnt = 0
for _ in range(N):
    i1, i2 = input().split()
    if i1 not in item_to_node.keys():
        item_to_node[i1] = icnt
        node_to_item[icnt] = i1
        icnt += 1
    if i2 not in item_to_node.keys():
        item_to_node[i2] = icnt
        node_to_item[icnt] = i2
        icnt += 1
    # 이번에 새로 추가된 아이템 개수만큼 전체 수 계속 늘려감
    for _ in range(icnt - len(graph)):
        graph.append([])
        degree.append(0)
    i1, i2 = item_to_node[i1], item_to_node[i2]
    graph[i1].append(i2)
    degree[i2] += 1

# 위상 정렬
ans = []
q = [i for i,v in enumerate(degree) if v==0]
while len(q) > 0:
    nq = []
    for cur in q:
        for nxt in graph[cur]:
            degree[nxt] -= 1
            if degree[nxt] == 0:
                nq.append(nxt)
    # 같은 레벨의 아이템들은 사전 순으로 정렬
    ans += sorted(node_to_item[v] for v in q)
    q = nq

if len(ans) != len(graph):
    print(-1)
else:
    print('\n'.join(ans))