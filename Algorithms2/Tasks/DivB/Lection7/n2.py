n = int(input())
array = []
for i in range(n):
    l, r = tuple(map(int, input().split()))
    array.append((l, 1))
    array.append((l + r, -1))
array.sort()
max = 0
col = 0
for i in range(n * 2):
    if array[i][1] == -1:
        col -= 1
    else:
        col += 1
    if col > max:
        max = col
print(max)