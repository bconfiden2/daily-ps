N = int(input())
arr = sorted(map(int, input().split()))

cnt = 0
for i, v in enumerate(arr):
    ldx, rdx = 0, N-1
    while ldx < rdx:
        tmp = arr[ldx] + arr[rdx]
        # 0이 존재할 수 있기 때문에 자기자신을 제외한 모든 배열 탐색
        if ldx == i:
            ldx += 1
        elif rdx == i:
            rdx -= 1
        # 그 외에는 일반적인 투포인터
        elif tmp < v:
            ldx += 1
        elif tmp > v:
            rdx -= 1
        else:
            cnt += 1
            break
print(cnt)
