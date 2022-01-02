shorts = set([" "])
for _ in range(int(input())):
    opt = input()
    words = opt.split()
    # 1번 규칙
    for i, v in enumerate(map(lambda x: x.lower()[0], words)):
        if v not in shorts:
            shorts.add(v)
            for idx, val in enumerate(words):
                if idx == i:
                    print("[" + val[0] + "]" + val[1:], end="\n" if idx==len(words)-1 else " ")
                else:
                    print(val, end="\n" if idx==len(words)-1 else " ")
            break
    else:
        # 2번 규칙
        for i, v in enumerate(opt.lower()):
            if v not in shorts:
                shorts.add(v)
                print(opt[:i] + "[" + opt[i] + "]" + opt[i+1:])
                break
        # 3번 규칙
        else:
            print(opt)

