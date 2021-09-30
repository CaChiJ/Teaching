d, r = map(int, input().split())

cnt = 0
result = []

while True:
    mod = d % r
    result.append(chr(mod + ord('0')) if mod <
                  10 else chr(mod - 10 + ord('A')))
    d //= r
    cnt += 1

    if d == 0:
        break

print(''.join(result)[::-1])
