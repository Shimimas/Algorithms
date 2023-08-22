def find_set(v):
    root = v
    while parent[root] != root:
        root = parent[root]
    i = v
    while parent[i] != i:
        j = parent[i]
        parent[i] = root
        i = j
    return root


n, m = tuple(map(int, input().split()))
orders = {}
for i in range(1, m + 1):
    orders[i] = tuple(map(int, input().split()))
q = int(input())
threads = list(map(int, input().split()))
threads_set = set(threads)
parent = [i for i in range(n + 1)]
for i in range(1, m + 1):
    if i not in threads_set:
        f = find_set(orders[i][0])
        s = find_set(orders[i][1])
        if f != s:
            parent[s] = f
            n -= 1
res_ar = []
for i in range(q - 1, -1, -1):
    res_ar.append(n)
    f = find_set(orders[threads[i]][0])
    s = find_set(orders[threads[i]][1])
    if f != s:
        parent[s] = f
        n -= 1
res_ar.reverse()
print(' '.join(map(str, res_ar)))