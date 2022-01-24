import sys

def cantor(N):
    if N==0: return "-"
    fix = cantor(N-1)
    return fix + (" "*(3**(N-1))) + fix

for N in map(int, sys.stdin):
    print(cantor(N))