import sys
sys.setrecursionlimit(10**6)                    # 재귀 호출 깊이 설정

n = int(input())

inorder = list(map(int, input().split()))
postorder = list(map(int, input().split()))

rootidx = [0] * (n+1)                           # 재귀호출시 현재 루트 값에 대한 인덱스 정보
for i in range(n):
    rootidx[inorder[i]] = i

def subtree(inl, inr, pol, por):                # 매 서브트리마다
    if inl > inr or pol > por:                  # 빈 트리일 시 종료
        return
        
    rt = postorder[por]                         # 루트값은 반드시 post 의 마지막 인덱스
    lsize = rootidx[rt] - inl                   # 왼쪽 서브트리의 크기
    
    print(rt, end=" ")                          # preorder, 루트 먼저 찍어준 뒤
    subtree(inl, rootidx[rt] - 1, pol, pol + lsize - 1) # 왼쪽 서브트리 호출
    subtree(rootidx[rt] + 1, inr, pol + lsize, por - 1) # 오른쪽 서브트리 호출

subtree(0, n-1, 0, n-1)
print()