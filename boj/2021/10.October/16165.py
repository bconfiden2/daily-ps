N, M = map(int, input().split())
# 멤버이름:속한팀
dic = {}
# 팀명:속한멤버들
members = {}
for n in range(N):
    team = input()
    members[team] = sorted(input() for _ in range(int(input())))
    for x in members[team]:
        dic[x] = team
for m in range(M):
    name = input()
    print(dic[name] if input()=="1" else "\n".join(members[name]))
