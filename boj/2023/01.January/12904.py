S, T = input(), input()
# 뒤에서부터 확인하면서
while len(T) > len(S):
    # 맨 뒤의 문자가 A면 그냥 빼주고
    # 맨 뒤의 문자가 B면 해당 B를 빼고 뒤집어준다
    T = T[:-1] if T[-1] == 'A' else T[:-1][::-1]
# T의 길이가 S가 될때까지 계속 빼주다가, 결과 비교
print(1 if T == S else 0)