n = int(input())
array = list(map(int, input().split()))
if n == 1:
    print(array[0])
else:
    prefix = [0] * (n + 1)
    for i in range(1, n + 1):
        prefix[i] = prefix[i - 1] + array[i - 1]
    max = array[0]
    for l in range(n + 1):
        r = l + 1
        while r < n + 1 and prefix[l] < prefix[r]:
            summ = prefix[r] - prefix[l]
            if summ > max:
                max = summ
            r += 1
print(max)