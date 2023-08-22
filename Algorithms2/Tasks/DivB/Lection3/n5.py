m = int(input())
sv = []
for i in range (m):
    sv.append(set(input()))
n = int(input())
numbers = []
max = 0
for i in range(n):
    numbers.append(input())
for el in numbers:
    tmp_set = set(el)
    max_tmp = 0
    for s in sv:
        if s <= tmp_set:
            max_tmp += 1
    if max_tmp > max:
        max = max_tmp
for el in numbers:
    tmp_set = set(el)
    max_tmp = 0
    for s in sv:
        if s <= tmp_set:
            max_tmp += 1
    if max_tmp == max:
        print(el)