n = int(input())
n_array = list(map(int, input().split()))
one = set()
many = set()
for i in range(n):
    if n_array[i] not in one and n_array[i] not in many:
        one.add(n_array[i])
    elif n_array[i] in one:
        many.add(n_array[i])
        one.remove(n_array[i])
print(len(one))