l, k = tuple(map(int, input().split()))
coords = list(map(int, input().split()))
mid = l // 2
if l % 2 == 1 and mid in coords:
    print(mid)
else:
    i_tmp = 0
    for i in range(len(coords)):
        if coords[i] < mid:
            i_tmp = i
    print(coords[i_tmp], coords[i_tmp + 1])