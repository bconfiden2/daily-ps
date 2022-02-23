s1, s2 = input(), input()
answer = [["" for c in range(1001)] for r in range(2)]
cur, nxt = 1, 0
for r in range(len(s2)):
    for c in range(len(s1)):
        if s2[r] == s1[c]: answer[nxt][c+1] = answer[cur][c] + s1[c]
        else: answer[nxt][c+1] = answer[cur][c+1] if len(answer[cur][c+1]) > len(answer[nxt][c]) else answer[nxt][c]
    cur, nxt = nxt, cur
ans = len(answer[cur][len(s1)])
print(ans)
if ans > 0:
    print(answer[cur][len(s1)])