short = input().split(":")
# 규칙 2번의 :: 이 발견될 경우에는 필요한 수만큼 0000 을 채워놓음
for i in range(len(short)-1):
    if short[i] == "":
        if short[i+1] == "":
            short = short[:i] + short[i+1:]    
        short[i] = ":".join("0000" for _ in range(8-len(short)+1))
        break
# 나머지 값들에는 앞에 0을 채워서 출력
print(":".join(v.zfill(4) for v in short))