import sys
iu = lambda: map(lambda x: int(x)-1, sys.stdin.readline().split())
for _ in range(int(input())):
    N = list(iu())[0]+1
    graph = [i for i in range(N)]
    for _ in range(N-1):
        A, B = iu()
        graph[B] = A
    p, q = iu()
    # 첫번째 노드의 부모들을 셋에 담아놓은 뒤
    arr = set([p])
    while p != graph[p]:
        p = graph[p]
        arr.add(p)
    # 두번째 노드의 부모들을 탐색해가며 공통될 경우 출력
    while True:
        if q in arr:
            print(q+1)
            break
        q = graph[q]