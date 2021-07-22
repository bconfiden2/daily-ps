while True:
    c = float(input())
    if c == 0.0: break
    overhang = 0
    value = 0
    tmp = 2
    while value < c:
        value += 1 / tmp
        tmp += 1
        overhang += 1
    print(f"{overhang} card(s)")
