first = list(map(int, input().split()))
second = list(map(int, input().split()))
counter = 0
while True:
    f = first[0]
    s = second[0]
    first.pop(0)
    second.pop(0)
    if (f > s or (f == 0 and s == 9)) and not (f == 9 and s == 0):
        first.append(f)
        first.append(s)
    else:
        second.append(f)
        second.append(s)
    counter += 1
    if len(first) == 0:
        print('second', counter)
        break
    elif len(second) == 0:
        print('first', counter)
        break
    elif counter >= 10 ** 6:
        print('botva')
        break