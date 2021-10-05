N = int(input())
edges = []
for _ in range(N):
    a, b = map(int, input().split())
    edges.append(tuple(sorted((a,b))))

# 5개 정점의 완전그래프일 때만 불가능한 경우
if N == 10:
    print(-1)
    exit()
    
# 토끼를 움직이는 횟수는 반드시 2회 이하
cross = {(1,3):((2,4),(2,5)),(1,4):((2,5),(3,5)),(2,5):((1,3),(1,4)),(2,4):((1,3),(3,5)),(3,5):((1,4),(2,4))}
collisions = set()
nodes = [0 for i in range(6)]
# 그래프에서 충돌의 전체 횟수 세고, 각 토끼들마다 자신이 몇개의 충돌을 일으키고 있는지 확인
for e in edges:
    if e in cross.keys():
        for oe in cross[e]:
            if oe in edges:
                collisions.add(tuple(sorted((e, oe))))
                nodes[e[0]] += 1
                nodes[e[1]] += 1
c, maxi = len(collisions), max(nodes)
# 애초에 충돌이 없었으면 0
if c == 0:
    print(0)
# 토끼 한마리를 움직여서 모든 충돌이 해소되면 1
elif c == maxi:
    print(1)
# 한마리 움직여도 충돌이 남아있으면 하나 더 옮겨야하므로 2
elif c > maxi:
    print(2)