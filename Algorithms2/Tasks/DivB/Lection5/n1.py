n, m = tuple(map(int, input().split()))
array = list(map(int, input().split()))
prefix = [0] * (n + 1)
for i in range(1, n + 1):
    prefix[i] = prefix[i - 1] + array[i - 1]
for i in range(m):
    l, r = tuple(map(int, input().split()))
    print(prefix[r] - prefix[l - 1])