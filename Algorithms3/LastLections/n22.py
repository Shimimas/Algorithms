def counter(n, k):
    if n == 1:
        n_array[n - 1] = 1
    elif n < 1:
        return 0
    else:
        if n_array[n - 1] == 0:
            for i in range(1, k + 1):
                n_array[n - 1] += counter(n - i, k)
    return n_array[n - 1]

n, k = tuple(map(int, input().split()))
n_array = [0] * n
counter(n, k)
print(n_array[-1])
