n = int(input())
dic = {}
for i in range(n) :
    book = input()
    if book in dic :
        dic[book] += 1
    else :
        dic[book] = 0
max = 0
for book in dic :
    if dic[book] > max :
        max = dic[book]

maxBooks = []
for book in dic :
    if dic[book] == max :
        maxBooks.append(book)
maxBooks.sort()
print(maxBooks[0])
