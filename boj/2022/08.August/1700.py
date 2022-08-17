N, K = map(int, input().split())
arr = list(map(int, input().split()))
st = set()
answer = 0
for i in range(K):
    if len(st) < N:
        st.add(arr[i])
    elif arr[i] not in st:
        answer += 1

        tmp = set([arr[i]])
        for j in range(i+1, K):
            if arr[j] in st and len(tmp) < N:
                tmp.add(arr[j])
                st.remove(arr[j])
        for v in st:
            if len(tmp) < N:
                tmp.add(v)
        st = tmp
print(answer)
