import sys
input = sys.stdin.readline

# 테스트케이스별로 bfs
def bfs(graph, q, fq):
    answer = 1
    while len(q) > 0:
        nq, nfq = [], []
        # 불이 먼저 4방향으로 확산됨
        for r, c in fq:
            for nr, nc in ((r+1,c),(r-1,c),(r,c+1),(r,c-1)):
                if 0 <= nr < R and 0 <= nc < C:
                    if not graph[nr][nc]:
                        nfq.append((nr, nc))
                        graph[nr][nc] = True
        # 불 확산 처리 이후에 상근이가 이동(이제 불이 붙으려는 칸으로 이동 X)
        for r, c in q:
            for nr, nc in ((r+1,c),(r-1,c),(r,c+1),(r,c-1)):
                if 0 <= nr < R and 0 <= nc < C:
                    if not graph[nr][nc]:
                        nq.append((nr, nc))
                        graph[nr][nc] = True
                # 상근이는 인덱스 범위를 벗어날 경우 탈출된 것
                else:
                    return str(answer)
        fq = nfq
        q = nq
        answer += 1
    return "IMPOSSIBLE"

for tc in range(int(input())):
    C, R = map(int, input().split())
    graph, q, fq = [], [], []
    for r in range(R):
        row = []
        for c, v in enumerate(input().strip()):
            # 빈 공간만 미방문 처리 해놓고
            if v == '.':
                row.append(False)
            # 나머지(벽, 상근, 불)은 전부 방문 처리
            else:
                row.append(True)
                # 어차피 상근이가 이미 지나간 공간은 불이 따라와봤자 무의미
                if v == '@':
                    q.append((r, c))
                # 불이 지나간 공간 역시 상근이가 못지나감
                elif v == '*':
                    fq.append((r, c))
        graph.append(row)
    print(bfs(graph, q, fq))
    