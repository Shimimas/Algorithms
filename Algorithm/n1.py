n = int(input())
array_n = list(map(int, input().split()))
m = int(input())
array_m = list(map(int, input().split()))
min_len = min(len(array_n), len(array_m))
ans_array = []
for i in range(-1, -1 * min_len - 1, -1):
    ans_array.append(array_n[i] + array_m[i])
if len(array_n) > min_len:
    for i in range(-1 * min_len - 1, -1 * len(array_n) - 1, -1):
        ans_array.append(array_n[i])
if len(array_m) > min_len:
    for i in range(-1 * min_len - 1, -1 * len(array_m) - 1, -1):
        ans_array.append(array_m[i])
ans_array.reverse()
print(len(ans_array) - 1)
print(' '.join(map(str, ans_array)))