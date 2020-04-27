import datetime

now = datetime.datetime.now()
if 3 <= now.month <= 5 :
    print("봄")
elif 6 <= now.month <= 8 :
    print("여름")
elif 9 <= now.month <= 11 :
    print("가을")
else :
    print("겨울")
