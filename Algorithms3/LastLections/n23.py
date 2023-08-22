def f(n):
    for i in range(2, n + 1):
        element = cache[i - 1]
        if i % 2 == 0:
            element = min(element, cache[i // 2])
        if i % 3 == 0:
            element = min(element, cache[i // 3])
        cache[i] = element + 1
    return cache[n]



n = int(input())
cache = [0] * (n + 1)
print(f(n))
way = [n]
i = n
while i > 1:
    if cache[i] == cache[i - 1] + 1:
        way.insert(0, i - 1)
        i -= 1
    elif i % 2 == 0 and cache[i // 2] + 1 == cache[i]:
        way.insert(0, i // 2)
        i //= 2
    else:
        way.insert(0, i // 3)
        i //= 3
print(' '.join(map(str, way)))

