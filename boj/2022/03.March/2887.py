import sys
N = int(input())
nodes = [tuple(map(int, l.split())) for i, l in enumerate(sys.stdin)]
sorted_nodes = [sorted(zip(range(N),(v[i] for v in nodes)), key=lambda x:x[1]) for i in range(3)]

parents = [i for i in range(N)]
def find(x):
    if parents[x] == x: return x
    parents[x] = find(parents[x])
    return parents[x]

ans = 0
cnt = 0
edges = []
# x, y, z 좌표들에 대해서
for k in range(3):
    tgt = sorted_nodes[k]
    # 정렬된 좌표값들을 기준으로, 특정 노드에서 해당 좌표가 가장 가까운 노드와 에지 연결
    for i in range(N):
        if i >= 1:
            edges.append((abs(tgt[i][1]-tgt[i-1][1]), tgt[i][0], tgt[i-1][0]))
        if i < N-1:
            edges.append((abs(tgt[i][1]-tgt[i+1][1]), tgt[i][0], tgt[i+1][0]))

# 현재 새롭게 추가된 에지들에 대해서 MST 갱신
for w, p, q in sorted(edges):
    P, Q = find(p), find(q)
    if P != Q:
        parents[P] = Q
        cnt += 1
        ans += w
    if cnt == N-1:
        break
print(ans)