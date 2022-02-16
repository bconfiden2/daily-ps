from collections import Counter
for t in range(int(input())):
    print(f"#{t+1} {'Yes' if list(Counter(input()).values()) == [2,2] else 'No'}")