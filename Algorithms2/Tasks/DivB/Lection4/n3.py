from sys import stdin

m = dict()
for s in stdin:
    s = s.split()
    for el in s:
        if el not in m:
            m[el] = 0
        m[el] += 1
res_array = []
for el in m:
    res_array.append((-m[el], el))
res_array.sort()
for el in res_array:
        print(el[1])