n = int(input())
pallets = []
for i in range(n):
    a, b = tuple(map(int, input().split()))
    if a > b:
        pallets.append((a, b))
    else:
        pallets.append((b, a))
pallets.sort(reverse=True)
res = 1
OldBig = pallets[0]
Big = pallets[0]
for i in range(1, n):
    if not (pallets[i][0] < Big[0] and pallets[i][1] < Big[1] or pallets[i][0] < OldBig[0] and pallets[i][1] < OldBig[1]):
        res += 1
        if pallets[i][1] > Big[1]:
            OldBig = Big
            Big = pallets[i]
print(res)