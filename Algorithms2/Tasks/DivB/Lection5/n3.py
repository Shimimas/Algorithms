n, m = tuple(map(int, input().split()))
students = list(map(int, input().split()))
rooms = list(map(int, input().split()))
rooms_t = [(rooms[i - 1], i) for i in range(1, m + 1)]
rooms_t = sorted(rooms_t, reverse=True)
max = 0
res_array = []
for l in range(n):
    r = 0
    while r < len(rooms_t) and rooms_t[r][0] - 1 >= students[l]:
        r += 1
    if r - 1 >= 0 and rooms_t[r - 1][0] - 1 >= students[l]:
        max += 1
        res_array.append(rooms_t[r - 1][1])
        rooms_t.remove(rooms_t[r - 1])
    else:
        res_array.append(0)
print(max)
for el in res_array:
    print(el)