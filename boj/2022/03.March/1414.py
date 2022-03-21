edges = []
total = 0
N = int(input())
for r in range(N):
    for c, v in enumerate(input()):
        # 입력받은 문자에 맞게 가중치로 변환
        v = (ord(v)-96 if v>='a' else ord(v)-38 if v>='A' else 0)
        # 가지고 있는 전체 랜선 길이
        total += v
        if r != c and v != 0:
            edges.append((v,r,c))
        
parents = [i for i in range(N)]
def find(x):
    if parents[x] == x: return x
    parents[x] = find(parents[x])
    return parents[x]

cnt = 0
# 에지들을 가중치 순으로 탐색하며 MST 구성(크루스칼)
for v,r,c in sorted(edges):
    R, C = find(r), find(c)
    if R != C:
        parents[R] = C
        # 전체 랜선 길이에서 하나씩 빼줌
        total -= v
        cnt += 1
    if cnt == N-1: break
print(-1 if cnt < N-1 else total)
