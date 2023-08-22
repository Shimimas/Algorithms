n, m = map(int, input().split())
matrix = [[0 for _ in range(m + 1)] for __ in range(n + 1)]
matrix[1][1] = 1
for i in range(2, n + 1):
    for j in range(2, m + 1):
        matrix[i][j] = matrix[i - 2][j - 1] + matrix[i - 1][j - 2]
print(matrix[-1][-1])