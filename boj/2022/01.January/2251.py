A, B, C = map(int, input().split())
s = set()
answer = set()
q = [(0,0)]

def check(xy, s, nq):
    if xy not in s:
        s.add(xy)
        nq.append(xy)

while len(q) > 0:
    nq = []
    for a, b in q:
        c = C - a - b
        if a == 0:
            answer.add(c)
        check((min(a+c, A), b), s, nq) # c -> a
        check((a, min(b+c, B)), s, nq) # c -> b
        check(((a-min(a,C-c)), b), s, nq) # a -> c
        check((a, (b-min(b,C-c))), s, nq) # b -> c
        check((a+b-B,B) if a+b>B else (0,a+b), s, nq) # a -> b
        check((A,a+b-A) if a+b>A else (a+b,0), s, nq) # b -> a
    q = nq
print(" ".join(map(str, sorted(answer))))