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
std = 1
# MST가 완성될때까지 반복
while cnt < N-1:
    edges = []
    # x, y, z 좌표들에 대해서
    for k in range(3):
        target = sorted_nodes[k]
        # 정렬된 값들을 기준으로 특정 노드에서 인덱스가 std 만큼 차이나는 노드와 에지 연결
        for i in range(N):
            tgt = find(target[i][0])
            if i >= std and tgt != find(target[i-std][0]):
                edges.append((abs(target[i][1]-target[i-std][1]), target[i][0], target[i-std][0]))
            if i < N-std and tgt != find(target[i+std][0]):
                edges.append((abs(target[i][1]-target[i+std][1]), target[i][0], target[i+std][0]))
    # std 는 1부터 시작해서 값이 증가하기 때문에, 가까운 순으로 탐색하게 됨
    std += 1

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