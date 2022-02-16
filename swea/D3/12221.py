for t in range(int(input())):
    a, b = input().split()
    ans = int(a)*int(b) if len(a)==1 and len(b)==1 else -1
    print(f"#{t+1} {ans}")