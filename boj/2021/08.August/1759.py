L, C = map(int, input().split())
# 문자들을 미리 사전순으로 배열해놓고 탐색
can = sorted(input().split())
# 출력할 정답을 담아놓음
answer = ['a' for _ in range(L)]

# 백트래킹으로 가능한 경우들 모두 탐색
def select(idx, vdx, jaeum, moeum):
	# 만약 모든 자릿수를 다 채웠을 경우에는
	if idx==L:
		# 자음과 모음 조건을 충족시킨다면 출력, 아니면 그대로 종료
		if moeum >= 1 and jaeum >= 2:
			for c in answer:
				print(c, end="")
			print()
		return
	# 현재 자릿값에 뽑아 넣을 문자 결정
	for i in range(vdx+1, C):
		# 해당 문자 넣어주고 다음 자릿수 재귀적으로 탐색
		answer[idx] = can[i]
		# 자음과 모음 개수 카운팅
		j, m = jaeum, moeum
		if can[i] in ('a','e','i','o','u'):
			m += 1
		else:
			j += 1
		select(idx+1, i, j, m)

select(0, -1, 0, 0)
