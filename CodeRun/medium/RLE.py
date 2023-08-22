s = input()
s_pars = []
prefix = [0]
flag = False
num = 0
counter = 0
for el in s:
    if el.isalpha():
        if not flag:
            counter += 1
            s_pars.append((1, counter))
            prefix.append(prefix[-1] + 1)
        else:
            counter += num
            s_pars.append((num, counter))
            prefix.append(prefix[-1] + 1 + len(str(num)))
        num = 0
        flag = False
    else:
        flag = True
        num *= 10
        num += int(el)
m = int(input())
res_ar = []
for i in range(m):
    l_find, r_find = tuple(map(int, input().split()))

    l = 0
    r = len(s_pars) - 1
    while l < r:
        m = (l + r) // 2
        if l_find <= s_pars[m][1]:
            r = m
        else:
            l = m + 1
    l_idx = l

    l = 0
    r = len(s_pars) - 1
    while l < r:
        m = (l + r) // 2
        if r_find <= s_pars[m][1]:
            r = m
        else:
            l = m + 1
    r_idx = l

    sum = 0
    if l_idx != r_idx:
        fl = s_pars[l_idx][1] - l_find + 1
        if fl == 1:
            sum += 1
        else:
            sum += len(str(fl)) + 1
        sl = s_pars[r_idx][0] - (s_pars[r_idx][1] - r_find)
        if sl == 1:
            sum += 1
        else:
            sum += len(str(sl)) + 1
        sum += prefix[r_idx] - prefix[l_idx + 1]
    elif l_find != r_find:
        sum = len(str(r_find - l_find + 1)) + 1
    else:
        sum = 1
    res_ar.append(sum)
print('\n'.join(map(str, res_ar)))
