s = input()
c = set(input())
d = dict()
r = 0
min_len = len(s) + 1
for l in range(len(s)):
    while r < len(s) and not c <= set(d):
        if s[r] not in d:
            d[s[r]] = 0
        d[s[r]] += 1
        r += 1
    if r - l < min_len and c == set(d):
        min_len = r - l
    if d[s[l]] > 1:
        d[s[l]] -= 1
    else:
        del d[s[l]]
if min_len != len(s) + 1:
    print(min_len)
else:
    print(0)