d, m, y = tuple(map(int, input().split()))
if d <= 12 and m > 12 or m <= 12 and d > 12 or d == m:
    print(1)
else:
    print(0)