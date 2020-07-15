t = int(input())

for tc in range(t) :
    word = input()
    print("#{} {}".format(tc+1, int(word == word[::-1])))