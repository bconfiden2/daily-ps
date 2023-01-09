N = int(input())
arr = list(map(int, input().split()))

# 뒤에서부터 오름차순 깨지는 지점 찾기
bef = -1
start = 0
for i in range(N-1, -1, -1):
    if arr[i] < bef:
        start = i
        break
    bef = arr[i]

# 해당 위치부터 끝까지 수들 중에, 해당 위치 다음으로 큰 값 찾기
nxt = 0
find = False
others = []

tmpp = sorted(arr[start:])
for i in range(len(tmpp)):
    if tmpp[i] == arr[start]:
        others.append(tmpp[i])
        if i == len(tmpp) - 1:
            nxt = -1
        else:
            nxt = tmpp[i+1]
        find = True
    if find:
        find = False
        continue
    others.append(tmpp[i])

# 해당 위치 다음 큰 값을 가장 앞에 두고, 그 뒤로는 다시 정렬해서
if nxt == -1:
    print(-1)
else:
    st = set(tmpp)
    st.remove(nxt)
    answer = []
    for i in range(start):
        answer.append(arr[i])
    answer.append(nxt)
    for v in sorted(st):
        answer.append(v)
    print(" ".join(map(str, answer)))