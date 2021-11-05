sentence = input()
for word in sentence.split():
    print(word[::-1], end=' ')
