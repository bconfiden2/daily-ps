import sys
input = lambda: map(int, sys.stdin.readline().split())
R, C, M = input()
graph = [[0 for _ in range(C)] for _ in range(R)]
diri = (-1,1,0,0)
sharks = dict()
for i in range(1, M+1):
    r,c,s,d,z = input()
    r,c,d = r-1,c-1,d-1
    graph[r][c] = i
    sharks[i] = [r,c,s,d,z]

ans = 0
# 방향 전환시 사용할 반대방향
dr = {0:1,1:0,2:3,3:2}
base = {0:0,1:R-1,2:C-1,3:0}
# 낚시왕이 한칸씩 오른쪽으로 이동(1번)
for c in range(C):
    # 낚시왕이 땅과 가장 가까운 상어를 잡아버림(2번)
    for r in range(R):
        if graph[r][c] != 0:
            ans += sharks[graph[r][c]][4]
            del sharks[graph[r][c]]
            break
    # 모든 상어들의 이동 처리(3번)
    ngraph = [[0 for _ in range(C)] for _ in range(R)]
    x = list(sharks.items())
    for i, (r,c,s,d,z) in x:
        if i not in sharks: continue
        # 상어의 다음 위치를 확인
        nr, nc, nd = r + diri[d]*s, c + diri[3-d]*s, d
        if not (0 <= nr < R and 0 <= nc < C):
            s -= abs((c if d//2==1 else r)-base[d])
            tgt = C-1 if d//2==1 else R-1
            cnt = s // tgt
            nd = dr[d] if cnt%2==0 else d
            # 최종 방향이 안바뀌었으면
            if d//2 == 1:
                nc = abs((base[dr[d]] if nd==d else base[d]) - (s%tgt))
            else:
                nr = abs((base[dr[d]] if nd==d else base[d]) - (s%tgt))

        # 만약 상어가 중복될 경우, 몸집이 큰 놈이 작은 놈을 먹어버림
        if ngraph[nr][nc] != 0:
            if z >= sharks[ngraph[nr][nc]][4]:
                del sharks[ngraph[nr][nc]]
            else:
                del sharks[i]
                continue
        # 상어를 다음 위치로 움직여줌
        ngraph[nr][nc] = i
        sharks[i][0] = nr
        sharks[i][1] = nc
        sharks[i][3] = nd
    graph = ngraph
print(ans)