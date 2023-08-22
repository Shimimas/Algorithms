d = int(input())
x, y = tuple(map(int, input().split()))
length_list = [
    (((x - 0)**2 + (y - 0)**2)**0.5, 1),
    (((x - d)**2 + (y - 0)**2)**0.5, 2),
    (((x - 0)**2 + (y - d)**2)**0.5, 3)]
length_list.sort()
if d == 0:
    if x == 0 and y == 0:
        print(0)
    else:
        print(1)
elif d > 0:
    if y <= -x + d and x >= 0 and y >= 0:
        print(0)
    else:
        print(length_list[0][1])
else:
    if y >= -x + d and x <= 0 and y <= 0:
        print(0)
    else:
        print(length_list[0][1])