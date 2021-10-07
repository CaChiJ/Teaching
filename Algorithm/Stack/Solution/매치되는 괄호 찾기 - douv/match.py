s = input().strip()

stack = list()
pairs = list()
isMatched = True


for i, ch in enumerate(s):
    if ch == '(' or ch == '{':
        stack.append((ch, i))
    elif ch == ')':
        if len(stack) > 0 and stack[-1][0] == '(':
            pairs.append((stack[-1][1], i))
            stack.pop()
        else:
            isMatched = False
            break
    elif ch == '}':
        if len(stack) > 0 and stack[-1][0] == '{':
            pairs.append((stack[-1][1], i))
            stack.pop()
        else:
            isMatched = False
            break

if isMatched and len(stack) == 0:
    for pair in pairs:
        print("%d %d" % (pair[0], pair[1]))
else:
    print("not match")
