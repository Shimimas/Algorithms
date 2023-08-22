n = int(input())
m = dict()
for i in range(n):
    d, a = tuple(map(int, input().split()))
    if d not in m:
        m[d] = 0
    m[d] += a
s = sorted(list(m))
for el in s:
    print(el, m[el])