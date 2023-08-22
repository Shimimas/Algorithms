n = int(input())
m = dict()
number = 1
for i in range(n):
    c = int(input())
    if c == 0:
        name = input()
        m[(name, number)] = dict()
        m[(name, number)][number] = input()
    else:
        for el in m:
            if c in m[el]:
                m[el][number] = input()
    number += 1
array = []
for el in m:
    array.append((len(m[el]), -el[1], el[0]))
array.sort(reverse=True)
print(array[0][2])