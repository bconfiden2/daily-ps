T = int(input())

for t in range(T):
    line = input()
    candi = ['A', 'B', 'C', 'D', 'E', 'F']
    answer = before = line[0]
    for t in line[1:]:
        if t != before:
            before = t
            answer += t
    
    if answer[0] not in candi or answer[-1] not in candi:
        print('Good')
    elif len(answer) == 3 and answer == 'AFC':
        print('Infected!')
    elif len(answer) == 4 and (answer[1:] == 'AFC' or answer[:-1] == 'AFC'):
        print('Infected!')
    elif len(answer) == 5 and answer[1:-1] == 'AFC':
        print('Infected!')
    else:
        print('Good')
