n = int(input())
if 1.5 * n < (n - 2) * 2 + 1:
    print('NO')
    l = [i for i in range(n)]
    l[0] = n
    print(' '.join(map(str, l)))
else:
    print('YES')