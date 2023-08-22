n = int(input())
first = [0] * 5001
second = [0] * 5001
third = [0] * 5001
for i in range(1, n + 1):
    first[i], second[i], third[i] = map(int, input().split())
res = [0] * (n + 1)
res[1] = first[1]
if n > 1:
    res[2] = min(first[1] + first[2], second[1])
for i in range(3, n + 1):
    res[i] = min(res[i - 1] + first[i], res[i - 2] + second[i - 1], res[i - 3] + third[i - 2])
print(res[-1])
