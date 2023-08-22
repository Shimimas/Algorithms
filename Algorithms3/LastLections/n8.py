k = int(input())
array = []
for i in range(k):
    array.append(tuple(map(int, input().split())))
max_x = array[0][0]
min_x = array[0][0]
max_y = array[0][1]
min_y = array[0][1]
for i in range(1, k):
    if array[i][0] > max_x:
        max_x = array[i][0]
    if array[i][0] < min_x:
        min_x = array[i][0]
    if array[i][1] > max_y:
        max_y = array[i][1]
    if array[i][1] < min_y:
        min_y = array[i][1]
print(min_x, min_y, max_x, max_y)