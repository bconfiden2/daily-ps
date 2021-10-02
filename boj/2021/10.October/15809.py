import sys
N, M = map(int, input().split())
army = [0] + [int(sys.stdin.readline()) for n in range(N)]
parent = [i for i in range(N+1)]

# 경로 압축
def find_(x):
    if parent[x] == x:
        return x
    parent[x] = find_(parent[x])
    return parent[x]

for _ in range(M):
    O, P, Q = map(int, sys.stdin.readline().split())
    P, Q = find_(P), find_(Q)
    # 동맹은 아무방향으로나 가능
    if O == 1:
        parent[Q] = P
        army[P] += army[Q]
        army[Q] = 0
    # 전투
    if O == 2:
        # P가 Q를 합병할 때
        if army[P] > army[Q]:
            army[P] -= army[Q]
            army[Q] = 0
            parent[Q] = P
        # Q가 P를 합병할 때
        elif army[P] < army[Q]:
            army[Q] -= army[P]
            army[P] = 0
            parent[P] = Q
        # 둘 다 멸망
        else:
            army[P] = army[Q] = 0

# 동맹은 루트노드 하나로 표현되니, 0 보다 큰 병력을 가진 루트노드를 찾음
answer = sorted(v for v in army if v > 0)
print(len(answer))
print(" ".join(map(str, answer)))