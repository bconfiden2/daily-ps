line = input()
sum = 0
for char in line :
    sum += ord(char) - 96 if ord(char) > 80 else ord(char) - 38

for i in range(2, sum) :
    if sum % i == 0 :
        print("It is not a prime word.")
        print(i)
        break
else :
    print("It is a prime word.")
