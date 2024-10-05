# TODO
money = float(input())
money = money * 100
cash = [25,10,5,1]
ans = 0
for i in cash:
    while(money>=i):
        ans += 1
        money -= i
print(ans)