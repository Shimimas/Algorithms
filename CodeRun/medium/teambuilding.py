def left_add(vertex):
    for el in left:
        if vertex not in graph or el not in graph[vertex]:
            return False
    return True


def right_add(vertex):
    for el in right:
        if vertex not in graph or el not in graph[vertex]:
            return False
    return True

n, m = tuple(map(int, input().split()))
graph = {}
for i in range(m):
    a, b = tuple(map(int, input().split()))
    if a not in graph:
        graph[a] = set()
    if b not in graph:
        graph[b] = set()
    graph[a].add(b)
    graph[b].add(a)
for i in range(1, n + 1):
    if i not in graph:
        graph[i] = set()
left = set()
right = set()
can = True
for i in sorted(graph, key=lambda x: len(graph[x])):
    if len(left) == 0 or left_add(i):
        left.add(i)
    elif len(right) == 0 or right_add(i):
        right.add(i)
    else:
        can = False
if can:
    if len(right) == 0:
        right.add(1)
        left.discard(1)
    print(len(left))
    for el in left:
        print(el, end=' ')
    print()
    for el in right:
        print(el, end=' ')
    print()
else:
    print(-1)
