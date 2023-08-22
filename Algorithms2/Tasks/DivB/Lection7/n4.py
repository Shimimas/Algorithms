def lbinsearch(x, l, r, array):
    while l < r:
        m = (l + r) // 2
        if x <= array[m]:
            r = m
        else:
            l = m + 1
    if x <= array[l]:
        return l
    else:
        return -1


def rbinsearch(x, l, r, array):
    while l < r:
        m = (l + r + 1) // 2
        if x >= array[m]:
            l = m
        else:
            r = m - 1
    if x >= array[l]:
        return l
    else:
        return -1


n, m = tuple(map(int, input().split()))
array = sorted([int(el)for el in input().split()])
for i in range(m):
    l, r = tuple(map(int, input().split()))
    r_res = rbinsearch(r, 0, n - 1, array)
    l_res = lbinsearch(l, 0, n - 1, array)
    if l_res == -1 or r_res == -1:
        print('0')
    else:
        print(r_res - l_res + 1)