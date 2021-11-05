s = input()
pos = [-1 for i in range(26)]
foundCount = 0

for idx, ch in enumerate(s):
    if pos[ord(ch) - ord('a')] == -1:
        foundCount += 1
        pos[ord(ch) - ord('a')] = idx

    if foundCount == 26:
        break

for i in pos:
    print(i, end=' ')
