def dfs(graph, visited, now, prev):
    visited[now] = 1
    for neib in graph[now]:
        if visited[neib] == 0 and visited[0] == 0:
            dfs(graph, visited, neib, now)
        elif visited[neib] == 1 and prev != neib and len(cycle) == 0:
            cycle.append(neib)
            visited[0] = -2
    visited[now] = 2
    if visited[0] == -2:
        if now == cycle[0]:
            visited[0] = -1
        else:
            cycle.append(now)


n = int(input())
graph = [[] for _ in range(n + 1)]
visited = [0 for _ in range(n + 1)]
cycle = []
for i in range(n):
    array = list(map(int, input().split()))
    for j in range(n):
        if array[j] == 1 and i >= j:
            graph[j + 1].append(i + 1)
            graph[i + 1].append(j + 1)
for i in range(1, n + 1):
    if visited[i] == 0:
        dfs(graph, visited, i, i)
if visited[0] == -1:
    print('YES')
    print(len(cycle))
    print(' '.join(map(str, cycle)))
else:
    print('NO')