n = int(input())
nl = list(map(int, input().split()))
nl.sort()
print(nl[n//2])