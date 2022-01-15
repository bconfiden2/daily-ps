N = int(input())
if N == 1:
    print(0)
    exit()
arr = list(map(int, input().split()))
visited = [False for _ in range(N)]
q = [0]
cnt = 1
while len(q) > 0:
    nq = []
    for cur in q:
        for i in range(1,arr[cur]+1):
            nxt = cur + i
            if nxt < N and not visited[nxt]:
                visited[nxt] = True
                nq.append(nxt)
                if nxt == N-1:
                    print(cnt)
                    exit()
    q = nq
    cnt += 1
print(-1)