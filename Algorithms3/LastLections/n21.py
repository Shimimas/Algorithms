def counter(i):
    if n_array[i] == 0:
        if i == 0:
            n_array[i] = 2
        elif i == 1:
            n_array[i] = 4
        elif i == 2:
            n_array[i] = 7
        else:
            n_array[i] = counter(i - 1) + counter(i - 2) + counter(i - 3)
    return n_array[i]

n = int(input())
n_array = [0] * 40
print(counter(n - 1))