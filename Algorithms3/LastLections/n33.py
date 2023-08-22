def dfs(graph, visited, now, color):
    visited[now] = color
    for neib in graph[now]:
        if visited[neib] == 0:
            dfs(graph, visited, neib, 3 - color)
        elif visited[neib] == visited[now]:
            visited[0] = -1


n, m = map(int, input().split())
graph = [[] for _ in range(n + 1)]
visited = [0 for _ in range(n + 1)]
for _ in range(m):
    s, e = map(int, input().split())
    graph[s].append(e)
    graph[e].append(s)
for i in range(1, n + 1):
    if visited[i] == 0:
        dfs(graph, visited, i, 1)
if visited[0] == 0:
    print('YES')
else:
    print('NO')