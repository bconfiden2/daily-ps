import keyword

print(keyword.kwlist)

print("ddd")
print("dfadsfasdfasdf", end=" /")
print()

a,b = map(int, input().split())
print(a + b)

line = input().split()
print(int(line[0]) + int(line[1]))
print(id(line))

x = 30
y = 20
z = x;
print(id(x))
print(id(y))
print(id(z))
