N, K = map(int, input().split())
S = [True if c=='T' else False for c in input()]
visited = [False for i in range(N+1)]
# bfs 시작위치 - 초기상태에서 뒷면 동전의 갯수
q = [sum(1 for v in S if v)]
visited[q[0]] = True
cnt = 0
while len(q) > 0:
    nq = []
    for cur in q:
        # 만약 전부 뒤집힌 상태라면 cnt 출력 후 종료
        if cur == N:
            print(cnt)
            exit()
        # 현재 뒷면 개수에서, 한번에 k 개를 뒤집었는데 그 중 뒷면으로 변하는 동전의 개수가 i
        for i in range(K+1):
            # 앞면으로 뒤집힐 동전들(K-i)은 현재 뒷면상태에 있는 동전보다 적어야 하고, 뒷면으로 뒤집힐 동전은 현재 앞면보다 적어야함
            if K-i <= cur and i <= N-cur:
                # 그렇게 K-뒤집기를 했을 때, 범위 안에 들어오고 미방문했다면 다음 너비에 넣어줌
                if 0 <= cur+2*i-K <= N and not visited[cur+2*i-K]:
                    visited[cur+2*i-K] = True
                    nq.append(cur+2*i-K)
    q = nq
    cnt += 1
print(-1)