N = int(input())
count = 0
nowN = N

while True:
    nowN = 10 * (nowN % 10) + (nowN % 10 + nowN // 10) % 10

    count += 1

    if nowN == N:
        break

print(count)
