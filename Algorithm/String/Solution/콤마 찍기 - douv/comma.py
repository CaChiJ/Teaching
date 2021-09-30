str = input()

splitedStr = []
splitedStr.extend([str[i:i+3] for i in range(len(str)-3, -1, -3)])

if len(str) % 3 != 0:
    splitedStr.append(str[0:len(str) % 3])

print(','.join(splitedStr[::-1]))
