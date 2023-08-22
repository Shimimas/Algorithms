from sys import stdin

m = dict()
for s in stdin:
    n, c = tuple(s.split())
    if n not in m:
        m[n] = 0
    m[n] += int(c)
names = sorted(m)
for n in names:
    print(n, m[n])