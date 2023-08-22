m = int(input())
array = []
i = 0
add_set = set()
d = dict()
while (t := tuple(map(int, input().split()))) != (0, 0):
    l, r = t
    if l < m and r > 0:
        if l < 0:
            l = 0
        if r > m:
            r = m
        if (l, r) not in add_set:
            add_set.add((l, r))
            d[i] = ((l, r))
            array.append((l, -1, i))
            array.append((r, 1, i))
            i += 1
if len(array) != 0:
    array.sort()
    col = 0
    res_array = []
    in_set = set()
    flag = False
    for i in range(len(array)):
        if i > 0 and array[i][0] - array[i - 1][0] > 0 and col == 1:
            for el in in_set:
                res_array.append(el)
        elif i > 0 and array[i][0] - array[i - 1][0] > 0 and col == 0:
            print("No solution")
            exit(0)
        if array[i][1] == -1:
            in_set.add(array[i][2])
            col += 1
        else:
            in_set.discard(array[i][2])
            col -= 1
    res_array_array = []