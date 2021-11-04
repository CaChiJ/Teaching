num = int(input())
sum = 0

for i in range(1, num):
    if num % i == 0:
        sum += i

if sum > num:
    print("{0:>5}  ABUNDANT".format(num))
elif sum < num:
    print("{0:>5}  DEFICIENT".format(num))
else:
    print("{0:>5}  PERFECT".format(num))
