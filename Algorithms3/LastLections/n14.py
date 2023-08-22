n = int(input())
array = list(map(int, input().split()))
dead_end = []
array_2 = [0]
can = True
for el in array:
    if array_2[-1] + 1 == el:
        array_2.append(el)
    elif len(dead_end) == 0 or dead_end[-1] > el:
        dead_end.append(el)
    else:
        can = False
    while len(dead_end) > 0 and dead_end[-1] - 1 == array_2[-1]:
        array_2.append(dead_end[-1])
        dead_end.pop()
if can and len(dead_end) == 0:
    print('YES')
else:
    print('NO')