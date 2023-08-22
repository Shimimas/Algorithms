queue = []
while (s := input()) != 'exit':
    s = s.split()
    if s[0] == 'push':
        queue.append(int(s[1]))
        print('ok')
    elif s[0] == 'pop':
        if len(queue) != 0:
            print(queue[0])
            queue.pop(0)
        else:
            print('error')
    elif s[0] == 'size':
        print(len(queue))
    elif s[0] == 'clear':
        queue.clear()
        print('ok')
    elif s[0] == 'front':
        if len(queue) != 0:
            print(queue[0])
        else:
            print('error')
print('bye')