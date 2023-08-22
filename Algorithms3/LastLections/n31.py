def dfs(graph, visited, now):
    visited[now] = True
    for neib in graph[now]:
        if not visited[neib]:
            dfs(graph, visited, neib)


n, m = map(int, input().split())
graph = [[] for _ in range(n + 1)]
visited = [False for _ in range(n + 1)]
for _ in range(m):
    s, e = map(int, input().split())
    graph[s].append(e)
    graph[e].append(s)
dfs(graph, visited, 1)
count = 0
for el in visited:
    if el:
        count += 1
print(count)
for i in range(1, n + 1):
    if visited[i]:
        print(i, end=' ')
print()
