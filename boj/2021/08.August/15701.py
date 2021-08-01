N = int(input())
print(sum(1 if i*i == N else 2 for i in range(1, int(N**0.5)+1) if N%i == 0))