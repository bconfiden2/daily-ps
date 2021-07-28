N = int(input())
st = sorted(list(map(int, input().split())))
answer = 0

# 첫번째 수를 고정적으로 뽑아놓고 나머지 두 수 결정
for idx in range(N-2):
    # 두 수를 결정하기 위해 투 포인터를 써서 앞뒤로 범위를 줄여 O(N) 에 탐색
    target, l, r = -st[idx], idx + 1, N-1
    while l < r:
        cur = st[l] + st[r]
        # 만약 두 수가 우리가 원하던 값이라면
        if cur == target:
            curl, curr = st[l], st[r]
            # 그리고 두 수가 같은 수라면 그 수들로부터 2개를 뽑는 경우의 수만큼 팀 구성 가능(정렬되어있기 때문)
            if curl == curr:
                # 조합 계산식
                answer += (r-l+1)*(r-l)//2
                break
            # 두 수가 다른 수라면, 왼쪽포인터가 가리키는 수의 갯수 * 오른쪽포인터가 가리키는 수의 갯수
            else:
                dl, dr = 0, 0
                # 왼쪽 수의 개수를 구함
                while st[l] == curl:
                    dl += 1
                    l += 1
                # 오른쪽 수의 개수
                while st[r] == curr:
                    dr += 1
                    r -= 1
                answer += dl * dr
        elif cur < target:
            l += 1
        elif cur > target:
            r -= 1
print(answer)