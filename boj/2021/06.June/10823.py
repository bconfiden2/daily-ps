import sys
print(sum(map(int, "".join(line.strip() for line in sys.stdin).split(",")))) 
