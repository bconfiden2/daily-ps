ans = ""
for tc in range(int(input())):
    a,b,c,d=map(int, input().split())
    ans += f"#{tc+1} {max(min(b,d)-max(a,c), 0)}\n"
print(ans)