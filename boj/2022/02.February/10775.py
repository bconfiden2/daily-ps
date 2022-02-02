import sys
sys.setrecursionlimit(100000)
G, P = int(input()), int(input())
pt = [i for i in range(G+1)]

def assign(x):
    # 할당에 실패할 경우 True 반환
    if x==0:
        return 0, True
    # 성공할 경우에는 해당 번호의 다음 할당값 조정
    if pt[x] == x:
        pt[x] -= 1
        return pt[x], False
    pt[x], flg = assign(pt[x])
    return pt[x], flg

cnt = 0
# 할당에 실패할때까지
for g in map(int, sys.stdin):
    if assign(g)[1]: break
    cnt += 1
print(cnt)