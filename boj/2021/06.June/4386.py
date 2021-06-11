import heapq

def dist(X, Y):
    return ((X[0] - Y[0])**2 + (X[1] - Y[1])**2) ** 0.5

def find_(x):
    global parent
    if parent[x] == -1:
        return x
    parent[x] = find_(parent[x])    # path compression
    return parent[x]

def union_(x, y):                   # 유니온파인드
    global parent
    x = find_(x)
    y = find_(y)
    parent[x] = y

n = int(input())
stars = [tuple(map(float, input().split())) for i in range(n)]

distances = [(dist(stars[i], stars[j]), (i,j)) for i in range(n) for j in range(i+1, n)]
heapq.heapify(distances)                    # 가능한 에지들에 대하여 모두 거리를 기준으로 정렬(중복 제거)

answer = 0
parent = [-1] * n

while len(distances):                       # 에지들을 짧은 연결 순서대로 검사하면서 (크루스칼)
    d, (x, y) = heapq.heappop(distances)
    if find_(x) != find_(y):                # 순환 구조가 이루어지지 않는다면 (유니온파인드로 검사)
        union_(x, y)                        # 두 노드를 연결해줌
        answer += d

print(f"{answer:.2f}")