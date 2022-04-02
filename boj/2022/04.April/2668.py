def dfs(i, can):
    # 현재노드 방문처리 + 이번 dfs의 방문목록인 can에 담음
    visited[i] = True
    can.append(i)
    # 만약 재귀호출 중에 순환이 발생할 경우, 싸이클에 속한 노드들 추가
    if arr[i] in can:
        x = arr[i]
        while x != i:
            ans.append(x)
            x = arr[x]
        ans.append(x)
    if not visited[arr[i]]: dfs(arr[i], can)

N = int(input())
arr = [int(input())-1 for _ in range(N)]
visited = [False for _ in range(N+1)]
ans = []
# 처리하지 않은 노드들을 방문하면서 ans 에 싸이클들을 모두 담음
for i in range(N):
    if not visited[i]: dfs(i, [])
print(len(ans))
print("\n".join(map(lambda x: str(x+1), sorted(ans))))
