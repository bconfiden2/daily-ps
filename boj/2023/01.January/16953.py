A, B = map(int, input().split())
st = set([A])

cnt = 1
q = [A]
while len(q):
    nq = []
    for cur in q:
        if cur == B:
            print(cnt)
            exit()
        for nxt in (cur*2, cur*10+1):
            if A <= nxt <= B and nxt not in st:
                st.add(nxt)
                nq.append(nxt)
    q = nq
    cnt += 1
print(-1)