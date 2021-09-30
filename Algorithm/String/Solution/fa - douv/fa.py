ALPHABET_COUNT = 26
count = [0 for i in range(ALPHABET_COUNT)]
str = input()

for ch in str:
    count[ord(ch) - ord('a')] += 1

for i in range(ALPHABET_COUNT):
    print("%c:%d" % (ord('a') + i, count[i]))
