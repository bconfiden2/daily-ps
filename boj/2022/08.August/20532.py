import sys
sys.setrecursionlimit(200000)

N = int(input())
arr = list(map(int, input().split()))
# 통신탑이 하나밖에 없는 경우도 존재
if N == 1:
    print(0)
    exit()
graph = [[] for _ in range(N)]
# 루트노드부터 정방향 트리 형성
for i, v in enumerate(map(int, input().split())):
    graph[v-1].append(i+1)

# n 의 모든 약수들을 반환해주는 함수
def get_divisor(n):
    front = []
    back = []
    for i in range(1, int(n ** (1 / 2)) + 1):
        if n % i == 0:
            front.append(i)
            if i != n // i:
                back.append(n // i)
    return front + back[::-1]

# 현 시점에서 특정 i값이 총 몇번 등장했는지
cnt = [0 for _ in range(100001)]
# 현 시점에서 i의 배수들이 총 몇번 등장했는지
dvs = [0 for _ in range(100001)]
def dfs(cur):
    t = arr[cur]
    tmp = get_divisor(t)

    # 상위 노드들 중 나의 배수들 카운팅
    ret = dvs[t]
    # 상위 노드들 중 나의 약수들 카운팅
    for v in tmp:
        ret += cnt[v]
        # 하위 노드들을 위해 나의 약수값들을 전파(하위 노드의 배수)
        dvs[v] += 1
    # 약수이자 배수인 수에 대한 중복 처리
    ret -= cnt[tmp[-1]]
    # 하위 노드들의 나의 배수값들이 나를 처리할 수 있도록 카운팅
    cnt[t] += 1

    # dfs
    for nxt in graph[cur]:
        ret += dfs(nxt)
    
    # 백트래킹
    cnt[t] -= 1
    for v in tmp:
        dvs[v] -= 1

    return ret

print(dfs(0))