import sys
input = sys.stdin.readline

# path compression 적용한 유니온파인드
def _find(x, parents):
    if x == parents[x]:
        return x
    parents[x] = _find(parents[x], parents)
    return parents[x]

for tc in range(int(input())):
    print(f"Scenario {tc+1}:")
    # 테스트케이스별로 루트배열 초기화하여 사용
    parents = [i for i in range(int(input()))]
    # 입력받는 에지들을 합쳐나감
    for _ in range(int(input())):
        a, b = map(int, input().split())
        a, b = _find(a, parents), _find(b, parents)
        if a != b:
            parents[a] = b
    # 검사할 노드들에 대해서는 루트값만 비교
    for _ in range(int(input())):
        u, v = map(int, input().split())
        print(1 if _find(u, parents) == _find(v, parents) else 0)
    print()
