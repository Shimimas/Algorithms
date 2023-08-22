def counter(n, i):
    c1 = n - i - 1
    c2 = n - c1 - 1
    return int(((1 + c1) / 2) * c1) + int(((1 + c2) / 2) * c2)

s = input()
n = len(s)
d = {}
iter_col = int(((1 + n) / 2) * n)
for i in range(n):
    if s[i] not in d:
        d[s[i]] = 0
    d[s[i]] += iter_col - counter(n, i)
for el in sorted(d):
    print(f'{el}: {d[el]}')