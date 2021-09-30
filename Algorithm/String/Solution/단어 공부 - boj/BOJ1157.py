ALPHABET_COUNT = 26
count = [0 for i in range(ALPHABET_COUNT)]
str = input().upper()

for ch in str:
    count[ord(ch) - ord('A')] += 1

maxCount = -1
maxChar = '?'

for i in range(ALPHABET_COUNT):
    if (maxCount < count[i]):
        maxCount = count[i]
        maxChar = chr(ord('A') + i)
    elif (maxCount == count[i]):
        maxChar = '?'

print(maxChar)
