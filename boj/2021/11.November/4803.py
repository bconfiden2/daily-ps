import sys
input = sys.stdin.readline

def _find(x, parent):
    if parent[x] < 0: return x
    parent[x] = _find(parent[x], parent)
    return parent[x]

tc = 1
n, m = map(int, input().split())
while n > 0 or m > 0:
    parent = [-1 for i in range(n+1)]
    # 모든 간선들에 대해서
    for _ in range(m):
        a, b = map(int, input().split())
        # 자기 자신으로 연결된 간선은 무조건 트리가 성립되지 않음
        if a == b:
            parent[a] = -2
        a, b = _find(a, parent), _find(b, parent)
        # 만약 두 트리의 루트가 같거나(순환), 둘 중 하나라도 트리가 아닐 경우
        if a == b or parent[a] == -2 or parent[b] == -2:
            # 둘 다 트리로써 성립되지 않음
            parent[a] = parent[b] = -2
        else:
            # 정상적으로 연결되는 경우 두 트리를 연결
            parent[a] = b

    # 루트 노드(-1)의 개수를 세어줌        
    total = sum(1 for v in parent if v == -1) - 1
    answer = "No trees." if total==0 else "There is one tree." if total==1 else f"A forest of {total} trees."
    print(f"Case {tc}: {answer}")
    tc += 1
    n, m = map(int, input().split())
