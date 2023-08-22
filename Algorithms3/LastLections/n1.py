with open('input.txt') as f:
    s = f.read()
d = {}
max = 0
for el in s:
    if el != ' ' and el != '\n':
        if el not in d:
            d[el] = 0
        d[el] += 1
        if d[el] > max:
            max = d[el]
m = sorted(d)
while max > 0:
    for el in m:
        if d[el] == max:
            print('#', end='')
            d[el] -= 1
        else:
            print(' ', end='')
    print()
    max -= 1
for el in m:
    print(el, end='')
print()