t = int(input())
for i in range(t) :
    line = input()
    stac = []
    for ch in line :
        if ch == '(' :
            stac.append(ch)
        else :
            if(len(stac) == 0) :
                print("NO")
                break
            stac.pop()
    else :
        if(len(stac) != 0) :
            print("NO")
        else :
            print("YES")
