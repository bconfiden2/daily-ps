N = int(input())
A = list(map(int, input().split()))
arr = [A[0]]

# 특정 값보다 크거나 같은 값들 중 가장 작은 값의 인덱스
def lower_bound(arr, val):
    ldx, rdx = 0, len(arr)
    while ldx < rdx:
        mdx = (ldx + rdx) // 2
        if arr[mdx] >= val:
            rdx = mdx
        else:
            ldx = mdx + 1
    return ldx

for v in A:
    # 만약 더 큰 값이 들어올 경우에는 길이 1 추가
    if v > arr[-1]:
        arr.append(v)
    # 그 외에는 lowerbound 값을 대체
    # arr 자체는 증가하는 부분수열대로 유지되지는 않지만, 길이는 유지 가능
    else:
        arr[lower_bound(arr, v)] = v
print(len(arr))
