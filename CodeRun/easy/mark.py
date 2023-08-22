n = int(input())
d = {}
for i in range(n):
    a, b = tuple(map(int, input().split()))
    d[a] = b
l = list(map(int, input().split()))
min = n
d1 = {}
for i in range(len(l)):
    if d[l[i]] not in d1:
        d1[d[l[i]]] = i
    else:
        if i - d1[d[l[i]]] < min:
            min = i - d1[d[l[i]]]
        d1[d[l[i]]] = i
print(min)
    