dp = [0] * 101
n = int(input())
a = sorted(list(map(int, input().split())))
dp[1] = a[1] - a[0]
dp[2] = a[2] - a[0]
for i in range(3, n):
    dp[i] = min(dp[i - 1], dp[i - 2]) + a[i] - a[i - 1]
    if min(dp[i - 1], dp[i - 2]) == dp[i - 1]:
        print(i, ' to ', i - 1)
    else:
        print(i, ' to ', i - 2)
print(dp[n - 1])