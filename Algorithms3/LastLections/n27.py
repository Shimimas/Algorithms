n, m = map(int, input().split())
matrix = [list(map(int, input().split())) for _ in range(n)]
for i in range(1, n):
    matrix[i][0] += matrix[i - 1][0]
for i in range(1, m):
    matrix[0][i] += matrix[0][i - 1]
for i in range(1, n):
    for j in range(1, m):
        matrix[i][j] += max(matrix[i - 1][j], matrix[i][j - 1])
x = m - 1
y = n - 1
way = []
while not (x == 0 and y == 0):
    if x - 1 >= 0 and y - 1 >= 0:
        if matrix[y - 1][x] > matrix[y][x - 1]:
            way.insert(0, 'D')
            y -= 1
        else:
            way.insert(0, 'R')
            x -= 1
    elif x - 1 >= 0:
        way.insert(0, 'R')
        x -= 1
    else:
        way.insert(0, 'D')
        y -= 1
print(matrix[-1][-1])
print(' '.join(way))