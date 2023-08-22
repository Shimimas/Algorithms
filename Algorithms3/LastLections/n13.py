s = input().split()
stack = []
for i in range(len(s)):
    if s[i].isdigit():
        stack.append(int(s[i]))
    else:
        if s[i] == '*':
            stack[-2] *= stack[-1]
        elif s[i] == '-':
            stack[-2] -= stack[-1]
        elif s[i] == '+':
            stack[-2] += stack[-1]
        stack.pop()
print(stack[0])