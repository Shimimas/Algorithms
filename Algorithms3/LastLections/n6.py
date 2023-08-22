m = int(input())
n = int(input())
array = []
ans_array = []
ans = 0
for i in range(n):
    a, b = tuple(map(int, input().split()))
    array.append((a, b, i))
for i in range(-1, -1 * len(array) - 1, -1):
    can = True
    for el in ans_array:
        if el[2] != array[i][2] and not (array[i][0] > el[1] or array[i][1] < el[0]):
            can = False
            break
    if can:
        ans += 1
    ans_array.append(array[i])
print(ans)
