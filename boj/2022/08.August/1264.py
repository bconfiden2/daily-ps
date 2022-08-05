while 1:
    line = input()
    if line == '#': break
    print(sum(1 for v in line if v in ('a','e','i','o','u','A','E','I','O','U')))
