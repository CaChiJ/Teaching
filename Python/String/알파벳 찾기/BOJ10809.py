s = input()

for i in range(26):
    print(s.find(chr(i + ord('a'))), end=' ')
