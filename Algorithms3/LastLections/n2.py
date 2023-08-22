k = int(input())
s = input()
l = 0
d = {s[0]: 1}
max_el = s[0]
max = 0
for r in range(1, len(s)):
    if s[r] not in d:
        d[s[r]] = 0
    d[s[r]] += 1
    if d[s[r]] > d[max_el]:
        max_el = s[r]
    other_els = (r - l + 1) - d[max_el]
    while l != r and other_els > k:
        d[s[l]] -= 1
        if s[l] == 0:
            del d[s[l]]
        other_els -= 1
        l += 1
    if r - l + 1 > max:
        max = r - l + 1
print(max)