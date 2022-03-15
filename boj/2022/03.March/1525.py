board = [input().split() for _ in range(3)]
# 보드에서 인덱스별 연결 가능한 인덱스들
diri = {1:(2,4),2:(1,3,5),3:(2,6),4:(1,5,7),5:(2,4,6,8),6:(3,5,9),7:(4,8),8:(5,7,9),9:(6,8)}
# 문자열에서 두 인덱스의 문자 스왑하는 함수
def swap(cur, i, j):
    i, j = min(i,j)-1, max(i,j)-1
    return cur[:i] + cur[j] + cur[i+1:j] + cur[i] + cur[j+1:]

# 입력받은 보드상태에서 0을 9로 바꿔주고, 큐에는 (보드상태, 현재빈칸위치) 가 들어감
q = []
for r in range(3):
    for c in range(3):
        if board[r][c] == '0':
            board[r][c] = '9'
            q.append(("".join("".join(row) for row in board), r*3+c+1))
ans = 0
visited = set()
visited.add(q[0][0])

while len(q) > 0:
    nq = []
    # 현재 너비의 모든 상태 검사해서
    for cur, cdx in q:
        # 만약 현재 보드가 목표와 동일할 경우에는 그대로 종료
        if cur == '123456789':
            print(ans)
            exit()
        # 현재 빈칸 위치에서 연결 가능한 다음 빈칸 위치들을 검사하여
        for ndx in diri[cdx]:
            # 다음 위치로 옮겼을 때 기존에 검사했던 상태가 아닐 경우에만 다음 너비에 추가
            nxt = swap(cur, cdx, ndx)
            if nxt not in visited:
                visited.add(nxt)
                nq.append((nxt, ndx))
    q = nq
    ans += 1
print(-1)