array = list(map(int, input().split()))
max = 0
for i in range(len(array)):
    min = 11
    if array[i] == 1:
        for j in range(len(array)):
            if array[j] == 2:
                if min > abs(j - i):
                    min = abs(j - i)
    if max < min and min != 11:
        max = min
print(max)