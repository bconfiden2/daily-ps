N = int(input())
# 용액들은 정렬된 상태로 시작
arr = sorted(map(int, input().split()))

# 용액 하나가 선정되었을 때, 나머지 두 용액을 투포인터로 찾음
def find_others(arr, target, v1dx):
    # 왼쪽 인덱스는 첫 용액 이후부터, 오른쪽 인덱스는 마지막부터
    ldx, rdx = v1dx+1, len(arr)-1
    lval, rval = arr[ldx], arr[rdx]
    # 찾으려는 두 용액의 합과 첫 용액(target)의 차이가 가장 작은 조합을 반환
    mini = abs(lval + rval - target)
    while ldx < rdx:
        cur = arr[ldx] + arr[rdx]
        if abs(cur - target) < mini:
            mini = abs(cur - target)
            lval, rval = arr[ldx], arr[rdx]
        if cur < target:
            ldx += 1
        elif cur > target:
            rdx -= 1
        else:
            break
    return lval, rval

answer = 10e10
# 용액이 전부 양의 값을 갖더라도 앞의 3개가 답이 되게끔 초기화
answer_pairs = arr[:3]
for idx, v1 in enumerate(arr):
    # 세 용액이 전부 양수일 경우, 음수가 껴있던 이전 조합보다 반드시 합이 더 커짐
    if v1 >= 0 or idx >= N-2: continue
    v2, v3 = find_others(arr, -v1, idx)
    # 세 용액의 합이 0 에 가장 가까울 경우 정답 갱신
    if abs(v1 + v2 + v3) < answer:
        answer = abs(v1 + v2 + v3)
        answer_pairs = (v1, v2, v3)
    if answer == 0:
        break
print(" ".join(map(str, answer_pairs)))