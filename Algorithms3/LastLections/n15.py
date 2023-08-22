n = int(input())
array = list(map(int, input().split()))
answers = [-1] * n
stack = []
for i in range(n):
    while len(stack) > 0 and stack[-1][0] > array[i]:
        answers[stack[-1][1]] = i
        stack.pop()
    stack.append((array[i], i))
print(' '.join(map(str, answers)))
