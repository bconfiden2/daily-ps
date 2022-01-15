asgn = {}
# 자릿수대로 가중치를 둬 알파벳별 총합 구하기
for _ in range(int(input())):
    for i, c in enumerate(input()[::-1]):
        asgn[c] = asgn.get(c, 0) + 10**i
# 가장 큰 값을 갖는 알파벳 순으로 9 부터 할당하면 정답
print(sum((9-i)*x for i, x in enumerate(sorted((v for v in asgn.values()), reverse=True))))