s = input()
counts = [0 for i in range(26)]

for ch in s:
    if ord('a') <= ord(ch) <= ord('z'):
        idx = ord(ch) - ord('a')
    else:
        idx = ord(ch) - ord('A')

    counts[idx] += 1

maxCount = -1
maxCountIdx = -1

for idx, count in enumerate(counts):
    if count > maxCount:
        maxCount = count
        maxCountIdx = idx
    elif count == maxCount:
        maxCountIdx = -1

if maxCountIdx == -1:
    print('?')
else:
    print(chr(ord('A') + maxCountIdx))
