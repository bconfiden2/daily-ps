N, M = map(int, input().split())
graph = [[] for _ in range(3*N)]
degree = [0 for _ in range(3*N)]
score = [0 for _ in range(3*N)]

# {이름:노드번호} 형식의 딕셔너리 유지
# 그래프 형성, 각 노드별 indegree 차수 관리
cnt = 1
dic = {input():0}
score[0] = 1
for _ in range(N):
    c, p1, p2 = input().split()
    if c not in dic.keys():
        dic[c] = cnt
        cnt += 1
    if p1 not in dic.keys():
        dic[p1] = cnt
        cnt += 1
    if p2 not in dic.keys():
        dic[p2] = cnt
        cnt += 1
    c, p1, p2 = dic[c], dic[p1], dic[p2]
    degree[c] += 2
    graph[p1].append(c)
    graph[p2].append(c)

# 위상정렬 과정에서 자신의 점수를 자식에게 반영시킴
q = [i for i in range(N) if degree[i] == 0]
while len(q):
    nq = []
    for cur in q:
        for nxt in graph[cur]:
            degree[nxt] -= 1
            score[nxt] += score[cur] * 0.5
            if degree[nxt] == 0:
                nq.append(nxt)
    q = nq

# 후보자들을 점수 순으로 나열
ans = []
for _ in range(M):
    v = input()
    ans.append((score[dic[v]] if v in dic.keys() else 0, v))
print(max(ans)[1])
