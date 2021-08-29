# 이진 탐색, 값을 찾으면 인덱스 반환
def binary_search(arr, val):
    ldx, rdx = 0, len(arr)-1
    while ldx <= rdx:
        mdx = (ldx + rdx) // 2
        if arr[mdx] < val:
            ldx = mdx + 1
        elif arr[mdx] > val:
            rdx = mdx - 1
        else:
            return mdx
    return None

for _ in range(int(input())):
    N = int(input())
    s1 = sorted(map(int, input().split()))
    M = int(input())
    # 수첩2의 값이 수첩1에서 발견되면 1 출력
    for v in map(int, input().split()):
        print(0 if binary_search(s1, v) == None else 1)