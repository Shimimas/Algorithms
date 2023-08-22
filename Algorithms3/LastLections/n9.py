n, m, k = tuple(map(int, input().split()))
matrix = []
for i in range(n):
    matrix.append(list(map(int, input().split())))
prefix_matrix = []
for i in range(n):
    prefix_sum = [0] * (m + 1)
    for j in range(1, m + 1):
        prefix_sum[j] = prefix_sum[j - 1] + matrix[i][j - 1]
    prefix_matrix.append(prefix_sum)
answers = []
for i in range(k):
    x1, y1, x2, y2 = tuple(map(int, input().split()))
    sum = 0
    for j in range(x1 - 1, x2):
        sum += prefix_matrix[j][y2] - prefix_matrix[j][y1 - 1]
    answers.append(sum)
print('\n'.join(map(str, answers)))