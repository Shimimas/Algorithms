n = int(input())
array = []
for i in range(n):
    l, r = tuple(map(int, input().split()))
    array.append((l, -1))
    array.append((r, 1))
array.sort()
col = 0
length = 0 
for i in range(n * 2):
    if col > 0:
        length += array[i][0] - array[i - 1][0]
    if array[i][1] == -1:
        col += 1
    else:
        col -= 1
print(length)