n = int(input())
d = {}
for i in range(n):
    s = input()
    s_tmp = ''
    for j in range(len(s) - 2):
        if j == 0:
            s_tmp = s[j:j + 3:1]
        else:
            sl = s[j:j + 3:1]
            if s_tmp not in d:
                d[s_tmp] = {}
            if sl not in d[s_tmp]:
                d[s_tmp][sl] = 0
            d[s_tmp][sl] += 1
            s_tmp = sl
summ = 0
for el in d:
    summ += len(d[el])
print(len(d))
print(summ)
for el in d:
    for le in d[el]:
        print(el, le, d[el][le])