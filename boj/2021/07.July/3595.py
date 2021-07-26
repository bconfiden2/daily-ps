n = int(input())
lst = []

for i in range(1, int(n**0.5)+1):
    if n % i == 0:
        lst.append(i)
        lst.append(n // i)

lst.sort()
a,b,c = min(((2*(a*b+b*c+c*a), (a,b,c)) for a in lst for b in lst for c in lst if a*b*c==n), key=lambda x:x[0])[1]
print(a,b,c)