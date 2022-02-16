from itertools import combinations
for t in range(int(input())):
    line = list(input())
    tmp = [int("".join(line))]
    # 가능한 모든 경우로 바꿔보고 그 중 최대값 최소값 확인
    for a, b in combinations(range(len(line)), 2):
        line[a], line[b] = line[b], line[a]
        if line[0] != "0":
            tmp.append(int("".join(line)))
        line[b], line[a] = line[a], line[b]
    print(f"#{t+1} {min(tmp)} {max(tmp)}")
