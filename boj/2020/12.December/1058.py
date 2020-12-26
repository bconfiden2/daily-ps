n = int(input())
graph = [[1 if v=='Y' else 0 for v in input()] for _ in range(n)]
graph2 = [[sum(graph[i][x]*graph[x][j] for x in range(n)) for j in range(n)] for i in range(n)]
graph3 = [[int(bool(graph[i][j]) or bool(graph2[i][j])) if i!=j else 0 for j in range(n)] for i in range(n)]
print(max([sum(graph3[i]) for i in range(n)]))


# import sys

# n = int(input())
# i = 0
# friends = [set()] * n

# for line in sys.stdin:
#     for idx, val in enumerate(line[i+1:]):
#         if val =='Y':
#             friends[i].add(idx)
#             friends[idx].add(i);
#     i += 1

# length = []
# for idx in range(n):
#     temp = friends[idx]
#     for id in friends[idx]:
#         temp = temp.union(friends[id])
#     if idx in temp:
#         temp.remove(idx)
#     length.append(len(temp))

# print(max(length))