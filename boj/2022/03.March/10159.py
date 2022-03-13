N = int(input())
M = int(input())
st = [set() for _ in range(N)]
gp = [[] for _ in range(N)]
# 그래프는 단방향으로 저장하여 비교 가능한 물건들끼리만 연결될 수 있도록
for _ in range(M):
    p, q = map(lambda x:int(x)-1, input().split())
    gp[p].append(q)

# 각 물건마다 연결 가능한 모든 물건들과 연결됨
for i in range(N):
    st[i].add(i)
    visited = [False for _ in range(N)]
    visited[i] = True
    q = [v for v in gp[i]]
    while len(q) > 0:
        nq = []
        for cur in q:
            # 그래프는 단방향인 대신 물건끼리 연결될 때 양방향으로 쏴줌
            st[i].add(cur)
            st[cur].add(i)
            for nxt in gp[cur]:
                if not visited[nxt]:
                    visited[nxt] = True
                    nq.append(nxt)
        q = nq
    
for i in range(N):
    print(N - len(st[i]))