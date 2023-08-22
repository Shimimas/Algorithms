from sys import setrecursionlimit

def dfs(graph, visited, now):
    visited[now] = 1
    for neib in graph[now]:
        if visited[neib] == 0:
            dfs(graph, visited, neib)
        elif visited[neib] == 1:
            visited[0] = -1
    visited[now] = 2
    top_sort.append(now)

setrecursionlimit(100000)
n, m = map(int, input().split())
graph = [[] for _ in range(n + 1)]
visited = [0 for _ in range(n + 1)]
top_sort = []
for i in range(m):
    s, e = map(int, input().split())
    graph[s].append(e)
for i in range(1, n + 1):
    if visited[i] == 0:
        dfs(graph, visited, i)
if visited[0] == -1:
    print(-1)
else:
    top_sort.reverse()
    print(' '.join(map(str, top_sort)))