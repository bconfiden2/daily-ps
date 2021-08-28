N = int(input())
M = int(input())
parents = [-1 for i in range(N+1)]

def _union(parents, x, y):
    # 두 노드의 루트를 찾은 다음,
    x = _find(parents, x)
    y = _find(parents, y)
    # 서로 다른 집합에 속해 있다면, 한쪽 집합을 다른쪽 집합의 자식으로 붙임
    if x != y:
        parents[x] = y

def _find(parents, x):
    # 부모가 없는 노드가 루트 노드
    if parents[x] == -1:
        return x
    # 루트 노드를 재귀적으로 찾고, 부모로 설정까지(Path Compression)
    parents[x] = _find(parents, parents[x])
    # 루트 노드 반환
    return parents[x]

for r in range(N):
    for c, v in enumerate(input().split()):
        if r >= c: continue
        if v == '1':
            _union(parents, r+1, c+1)

print("YES" if len(set([_find(parents, v) for v in map(int, input().split())])) == 1 else "NO")