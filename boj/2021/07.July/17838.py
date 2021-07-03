import sys
T = int(input())
for line in sys.stdin:
    line = line.strip()
    able = False
    if len(line) == 7:
        if line[0] == line[1] and line[4] == line[0]:
            if line[2] == line[3] and line[5] == line[6] and line[5] == line[3]:
                if line[0] != line[2]:
                    able = True
    print(1 if able else 0)
