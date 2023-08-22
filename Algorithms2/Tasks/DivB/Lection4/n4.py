from sys import stdin

summ = 0
m = dict()
names_array = []
for s in stdin:
    s = s.split()
    col = int(s[-1])
    name = ' '.join(s[:-1])
    names_array.append(name)
    summ += col
    m[name] = col
first_num = summ / 450
places = dict()
sec_sum = 0
array = []
for el in m:
    f = m[el] / first_num
    s = int(f)
    places[el] = [f - s, -s, el]
    array.append(places[el])
    sec_sum += -places[el][1]
array = sorted(array, reverse=True)
i = 0
while sec_sum < 450:
    places[array[i][2]][1] -= 1
    i += 1
    if i == len(array):
        i = 0
    sec_sum += 1
for nam in names_array:
    print(nam, -places[nam][1])