from collections import Counter
N, S = map(int, input().split())
arr = list(map(int, input().split()))
def pp(s, e):
	ret = [0]
	for i in range(e-1, s-1, -1):
		for j in range(len(ret)):
			ret.append(arr[i] + ret[j])
	return ret

# 배열을 절반으로 나눈 뒤 가능한 모든 조합을 구해놓음
fa, ba = pp(0, N//2), pp(N//2, N)
# 둘 중 하나의 배열에 대해서 각 원소가 몇개씩 존재하는지 세어놓은 뒤
bc = Counter(ba)
# 나머지 배열의 원소들을 탐색하며 합이 S가 되는 개수를 확인
print(sum(bc[S-v] for v in fa)-(1 if S==0 else 0))