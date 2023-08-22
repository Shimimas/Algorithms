n, k = tuple(map(int, input().split()))
array = sorted(list(map(int, input().split())))
l = 0
r = array[-1] - array[0] + 1
while l < r:
    m = (l + r) // 2
    k_tpm = k - 1
    lenght = array[0] + m
    for i in range(1, n):
        if array[i] > lenght:
            k_tpm -= 1
            lenght = array[i] + m
    if k_tpm >= 0:
        r = m
    else:
        l = m + 1
print(l)