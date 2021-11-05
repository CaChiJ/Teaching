s = input()
count = [0 for i in range(26)]

for ch in s:
    count[ord(ch) - ord('a')] += 1

for i in range(26):
    print("{0}:{1}".format(chr(i + ord('a')), count[i]))
