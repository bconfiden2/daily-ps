from itertools import combinations
N = int(input())
people = list(map(int, input().split()))
graph = [[] for _ in range(N)]
for n in range(N):
    for v in map(lambda x: int(x)-1, input().split()[1:]):
        graph[n].append(v)

# 연결되어있는 같은 그룹을 방문처리하는 함수
def dfs(cur, flg, visited):
    visited[cur] = 0
    for nxt in graph[cur]:
        if visited[nxt] == flg:
            dfs(nxt, flg, visited)

def check(lst):
    # 그룹 1과 그룹 2를 구분한 뒤, dfs 를 전부 돌렸을 때 나뉘는 그룹이 2개일 경우 그룹끼리 연결되어있다는 뜻
    visited = [2 for _ in range(N)]
    for v in lst:
        visited[v] = 1
    cnt = 0
    for i in range(N):
        if visited[i] != 0:
            dfs(i, visited[i], visited)
            cnt += 1
    return cnt == 2

# 확인 가능한 모든 조합들에 대해서 두 그룹의 차이가 낮은 순서대로 확인
total = sum(people)
for v, comb in sorted((abs(total-2*sum(people[v] for v in comb)), comb) for r in range(1, N//2+1) for comb in combinations(range(N), r)):
    if check(comb):
        print(v)
        break
else:
    print(-1)