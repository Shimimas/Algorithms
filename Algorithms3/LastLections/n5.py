def recursia(array):
    if len(array) <= 1:
        return 0
    min = array[0]
    min_idx = 0
    for i in range(1, len(array)):
        if array[i] < min:
            min = array[i]
            min_idx = i
    res = min * (len(array) - 1)
    new_ar = []
    for i in range(len(array)):
        array[i] -= min
        if array[i] == 0:
            res += recursia(new_ar)
            new_ar.clear()
        else:
            new_ar.append(array[i])
    res += recursia(new_ar)
    return res
    

n = int(input())
array = []
for i in range(n):
    array.append(int(input()))
print(recursia(array))
