deque = []
while (s := input()) != 'exit':
    s = s.split()
    if s[0] == 'push_front':
        deque.insert(0, int(s[1]))
        print('ok')
    elif s[0] == 'push_back':
        deque.append(int(s[1]))
        print('ok')
    elif s[0] == 'pop_front':
        if len(deque) != 0:
            print(deque[0])
            deque.pop(0)
        else:
            print('error')
    elif s[0] == 'pop_back':
        if len(deque) != 0:
            print(deque[-1])
            deque.pop()
        else:
            print('error')
    elif s[0] == 'size':
        print(len(deque))
    elif s[0] == 'clear':
        deque.clear()
        print('ok')
    elif s[0] == 'front':
        if len(deque) != 0:
            print(deque[0])
        else:
            print('error')
    elif s[0] == 'back':
        if len(deque) != 0:
            print(deque[-1])
        else:
            print('error')
print('bye')