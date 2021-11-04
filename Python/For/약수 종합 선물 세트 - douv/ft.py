num = int(input())
count = 0
sum = 0
product = 1

for i in range(1, num + 1):
    if num % i == 0:
        print(i, end=' ')
        count += 1
        sum += i
        product *= i    # "product = product * i % 10" work efficiently

print()
print(count)
print(sum)
print(product % 10)
