import sys
n, m = map(int, sys.stdin.readline().rstrip().split())
noHear = set()
for i in range(n) :
    noHear.add(sys.stdin.readline().rstrip())
noSee = set()
for i in range(m) :
    noSee.add(sys.stdin.readline().rstrip())
noHearSee = noHear & noSee
print(len(noHearSee))
for i in sorted(noHearSee) :
    print(i)
