N, i, j = tuple(map(int, input().split()))
if i > j:
    i, j = j, i
len1 = N - j + i - 1
len2 = j - i - 1
if len1 < len2:
    print(len1)
else:
    print(len2)