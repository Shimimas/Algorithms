n = int(input())
n_array = list(map(int, input().split()))
m = int(input())
m_array = list(map(int, input().split()))
matrix = [[0 for _ in range(m + 1)] for __ in range(n + 1)]
for i in range(1, n + 1):
    for j in range(1, m + 1):
        if n_array[i - 1] == m_array[j - 1]:
            matrix[i][j] = matrix[i - 1][j - 1] + 1
        else:
            matrix[i][j] = max(matrix[i - 1][j], matrix[i][j - 1])
way = []
x = n
y = m
while x != 0 and y != 0:
    if matrix[x - 1][y] == matrix[x][y - 1] and matrix[x][y - 1] != matrix[x][y]:
        way.insert(0, n_array[x - 1])
        x -= 1
        y -= 1
    elif matrix[x - 1][y] >= matrix[x][y - 1]:
        x -= 1
    else:
        y -= 1
print(' '.join(map(str, way)))
