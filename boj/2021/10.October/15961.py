import sys
N, d, k, c = map(int, input().split())
arr = [int(l) for l in sys.stdin]
# 현재 윈도우가 가지고 있는 접시의 종류와 개수들
st = {}
# 시작 시 추가 접시(c)는 기본적으로 하나 포함시킴
for v in arr[:k] + [c]:
    st[v] = st.get(v, 0) + 1
ldx, rdx = 0, k
answer = len(st.keys())
# ldx가 0 ~ N-1 까지, 각각 k만큼의 윈도우 확인
for i in range(1, N):
    st[arr[ldx]] -= 1
    if st[arr[ldx]] == 0:
        del st[arr[ldx]]
    st[arr[rdx]] = st.get(arr[rdx], 0) + 1
    # 각 윈도우마다 최대값 갱신
    answer = max(len(st.keys()), answer)
    ldx += 1
    rdx = (rdx+1)%N
print(answer)