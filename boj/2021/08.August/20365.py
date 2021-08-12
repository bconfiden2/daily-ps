N = int(input())
tg = input()
# 문자열에서 연속된 R 과 B 들을 합쳐주는 작업
bc = out = tg[0]
for c in tg[1:]:
    if c != bc:
        bc = c
        out += c
# 압축된 문자열에서 R 과 B 의 개수 중 더 작은 값 + 1 이 답이 됨
R = sum(int(c=='R') for c in out)
print(min(R, len(out)-R) + 1)
