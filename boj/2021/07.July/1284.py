width = [4,2,3,3,3,3,3,3,3,3]
line = input().strip()
while line != '0':
    print(sum(width[int(c)] for c in line) + 1 + len(line))
    line = input().strip()
