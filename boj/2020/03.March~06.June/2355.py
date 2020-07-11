A, B = map(int, input().split())
a = min(A, B)
b = max(A, B)
ans = ((a + b) * (b - a + 1)) / 2
print(int(ans))
