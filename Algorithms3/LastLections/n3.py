def lbinsearch(x, n):
    l = 0
    r = n - 1
    while l < r:
        m = (l + r + 1) // 2
        if n_array[m] < x:
            l = m
        else:
            r = m - 1
    if n_array[l] < x:
        return l
    else:
        return -1

n = int(input())
n_array = sorted(list(set(map(int, input().split()))))
k = int(input())
k_array = list(map(int, input().split()))
for el in k_array:
    res = lbinsearch(el, len(n_array))
    if res != -1:
        print(res + 1)
    else:
        print(0)