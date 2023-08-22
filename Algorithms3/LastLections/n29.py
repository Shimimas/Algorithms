n = int(input())
n_array = [0]
if n != 0:
    k2 = 0
    for _ in range(n):
        n_array.append(int(input()))
    matrix = [[30001 for _ in range(n + 2)] for __ in range(n + 1)]
    matrix[0][1] = 0
    matrix[0][0] = 0
    for i in range(1, n + 1):
        for j in range(1, n + 1):
            if n_array[i] <= 100:
                matrix[i][j] = min(matrix[i - 1][j] + n_array[i], matrix[i - 1][j + 1])
            else:
                matrix[i][j] = min(matrix[i - 1][j - 1] + n_array[i], matrix[i - 1][j + 1])
    min = 30001
    k1 = 0
    way = []
    for i in range(1, n + 1):
        if matrix[-1][i] <= min:
            min = matrix[-1][i]
            k1 = i - 1
    k_tmp = k1 + 1
    if n == 1 and n_array[1] > 100:
        k2 = 0
        k1 = 1
    for i in range(n, 0, -1):
        if n_array[i] <= 100:
            if matrix[i][k_tmp] == matrix[i - 1][k_tmp + 1]:
                k2 += 1
                k_tmp += 1
                way.insert(0, i)
        else:
            if matrix[i][k_tmp] == matrix[i - 1][k_tmp + 1]:
                k2 += 1
                k_tmp += 1
                way.insert(0, i)
            else:
                k_tmp -= 1
    print(min)
    print(k1, k2)
    print(' '.join(map(str, way)))
else:
    print(0)
    print(0, 0)