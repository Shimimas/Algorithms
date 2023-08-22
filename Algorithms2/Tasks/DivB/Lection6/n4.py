a, k, b, m, x = tuple(map(int, input().split()))
l = 0
r = x
while l < r:
    mid = (l + r) // 2
    if x <= mid * (a + b) - ((mid // k) * a + (mid // m) * b):
        r = mid
    else:
        l = mid + 1
print(l)