n = int(input())
logic = [-1] * 26
for i in range(n):          # a 는 b 이면서 c 일 수 없다 == 각 노드는 하나의 노드만 가리킨다
    x, y = map(lambda x: ord(x)-97, input().split(" is "))
    logic[x] = y

m = int(input())
for i in range(m):          # m 이 최대 10개이고, n 은 26개이기 때문에 dfs 돌리듯 논법을 탐색
    visited = [False] * 26
    x, y = map(lambda x: ord(x)-97, input().split(" is "))
    while logic[x] != -1:   # 연결된 논법의 끝까지 탐색
        visited[x] = True
        x = logic[x]
        if visited[x]:      # 논법이 순환하면 
            break
        if x==y:            # 논법 성립하면 종료
            break
    print('T' if x==y else 'F')
