# 단어를 딕셔너리에 넣을 키값으로 바꿔주는 함수 - 중간부분을 정렬해서 저장함으로써 같은 단어 확인
def convert(word):
    return (word[0] + "".join(sorted(word[1:-1])) + word[-1]) if len(word) > 1 else word

# 사전에 있는 단어들을 딕셔너리로 관리
words = {}
for _ in range(int(input())):
    key = convert(input())
    # 각 단어마다 해석될 수 있는 경우의 수를 저장
    words[key] = words.get(key, 0) + 1

for _ in range(int(input())):
    found = False
    cnt = 1
    # 입력받은 문장의 단어들을 검사하면서
    for target in input().split():
        key = convert(target)
        # 해당 단어가 해석될 수 있는 경우의 수를 쭉 곱해줘서 문장의 해석 방법 카운트
        if words.get(key, 0) > 0:
            cnt *= words[key]
            found = True
    # 문장에 존재하는 모든 단어가 사전에 없었다면 0 출력
    print(cnt if found else 0)