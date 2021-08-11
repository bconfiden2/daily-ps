n = int(input())
grp = [int(input()) for i in range(n)]
# 정렬된 원소 순서대로 그리디하게 값을 증가시켜나가기 위해 사용
can = sorted(list(set(grp)))
answer = 0
bef = -1

# 처음 들어온 배열에 대해서 연속된 같은 값들을 하나로 압축시켜줌
# 특정 위치를 눌렀을 때 그 주변의 값들을 검사하지 않고 하나로 간주하고 처리하기
arr = []
for val in grp:
    if val != bef:
        arr.append(val)
    bef = val

bef = -1
for candx in range(len(can)-1):
    # 현재 원소들의 최소값
    cur = can[candx]
    # 현재 최소값을 갖는 원소들이 바뀌어야하는 다음 최소값
    nxt = can[candx+1]

    # 원소의 값들을 증가시킨 후, 주변의 같은 값들을 하나로 다시 압축시키는 과정 
    tmp = []
    vdx = 0
    # 배열을 쭉 탐색해나가면서
    while vdx < len(arr):
        # 만약 원소가 최소값이거나, 바뀌어야하는 값이라면
        if arr[vdx] in (cur,nxt):
            while vdx < len(arr):
                # 그 옆의 원소가 최소값이면 그만큼 ADD 연산 수행했다고 보고
                if arr[vdx] == cur:
                    answer += (nxt-cur)
                # 그 옆의 원소가 바뀔 값이면 연산 수행은 없음
                elif arr[vdx] == nxt:
                    answer += 0
                # 다른 원소라면 
                else:
                    break
                vdx += 1
            # 다른 원소가 나와서 break 될때까지의 모든 원소들은, nxt 값 1개로 압축됨
            tmp.append(nxt)
        else:
            tmp.append(arr[vdx])
            vdx += 1
    # 이번 라운드에서 생성된 배열을 다음 라운드 인풋으로
    arr = tmp

print(answer)