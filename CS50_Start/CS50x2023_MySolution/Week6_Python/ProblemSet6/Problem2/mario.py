# TODO
print("Please input height")
height = input()
n = int(height)
print("Height:"+height)
cnt = 0
for i in range(n):
    cnt += 1
    for _ in range(n - cnt):
        print(" ",end='')
    for _ in range(cnt):
        print("#",end='')
    print()