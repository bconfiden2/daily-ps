N, M, H = map(int, input().split())
start = (0,0)
mcm = []

# 민트초코우유들의 위치를 리스트로 관리
for r in range(N):
    line = list(map(int, input().split()))
    for c, w in enumerate(line):
        if w == 2:
            mcm.append((r,c))
        if w == 1:
            start = (r,c)

L = len(mcm)
# 민초우유들 간의 거리를 미리 2차원배열로 구해놓음(시작 지점도 포함)
distance = [[abs(n1[0]-n2[0])+abs(n1[1]-n2[1]) for n2 in mcm+[start]] for n1 in mcm+[start]]
# 백트래킹 시 사용해줄 방문여부에 대한 배열
visited = [False for i in range(L)]
answer = 0

# 백트래킹으로 가능한 민초 방문들 탐색(최대 10개로 10 팩토리얼)
def select(num, cur, health):
    global answer
    # 만약 현재 위치에서 시작 지점으로 돌아갈 수 있으면, 최대값 갱신
    if num > answer:
        if health >= distance[cur][L]:
            answer = num
    for i in range(L):
        # 마시지 않은 민초우유들 중에서 하나를 골라 마시러 출발할건데
        if not visited[i]:
            # 해당 위치까지 체력이 뒷받침될 경우에만 마시러 감
            if health >= distance[cur][i]:
                visited[i] = True
                # 마시러 갔다고 재귀적으로 처리
                select(num+1, i, health+H-distance[cur][i])
                visited[i] = False

select(0, L, M)
print(answer)
