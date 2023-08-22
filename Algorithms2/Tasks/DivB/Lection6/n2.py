def lbinsearch(x, l, r, array):
    while l < r:
        m = (l + r) // 2
        if x <= array[m]:
            r = m
        else:
            l = m + 1
    if x == array[l]:
        return l + 1
    else:
        return 0


def rbinsearch(x, l, r, array):
    while l < r:
        m = (l + r + 1) // 2
        if x >= array[m]:
            l = m
        else:
            r = m - 1
    if x == array[l]:
        return l + 1
    else:
        return 0


n = int(input())
array = sorted(list(map(int, input().split())))
k = int(input())
orders = list(map(int, input().split()))
for o in orders:
    print(lbinsearch(o, 0, n - 1, array), rbinsearch(o, 0, n - 1, array))