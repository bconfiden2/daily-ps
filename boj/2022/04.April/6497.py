def find(x):
    if parent[x] == x: return x
    parent[x] = find(parent[x])
    return parent[x]

import sys
sys.setrecursionlimit(200000)
input = lambda: tuple(map(int, sys.stdin.readline().split()))
m, n = input()
while m != 0:
    parent = [i for i in range(m)]
    edges = sorted((input() for _ in range(n)), key=lambda x:x[2])
    mst = cnt = 0
    # 간선들을 가중치 기준으로 정렬한 뒤 크루스칼 돌리기
    for p, q, w in edges:
        p, q = find(p), find(q)
        if p == q: continue
        parent[p] = q
        mst += w
        cnt += 1
        if cnt == m-1:
            break
    print(sum(w for p,q,w in edges) - mst)
    m, n = input()