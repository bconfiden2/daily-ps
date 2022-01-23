n = int(input())
ht = [[]] + [list(map(int, input().split()))[1:] for _ in range(n)]
visited = [False for _ in range(n+1)]
grp = [set(), set()]
# 모든 노드들이 두개로 배분될때까지 반복
for i in range(1, n+1):
    # 특정 노드를 시작으로 할 경우 width 가 하나씩 넓어질 때 마다
    # 청팀과 백팀을 나눠가며 서로 싫어하는 사람들을 할당
    if not visited[i]:
        q = [i]
        visited[i] = True
        flg = 0
        while len(q) > 0:
            nq = []
            for cur in q:
                grp[flg].add(cur)
                for nxt in ht[cur]:
                    if not visited[nxt]:
                        visited[nxt] = True
                        nq.append(nxt)
            q = nq
            flg = (flg + 1) % 2
print(len(grp[0]))
print(" ".join(map(str, sorted(grp[0]))))
print(len(grp[1]))
print(" ".join(map(str, sorted(grp[1]))))