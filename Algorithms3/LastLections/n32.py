from sys import setrecursionlimit

def dfs(graph, visited, now, comp, comps):
    if comp not in comps:
        comps[comp] = set()
    comps[comp].add(now)
    visited[now] = comp
    for neib in graph[now]:
        if not visited[neib]:
            dfs(graph, visited, neib, comp, comps)


with open('input.txt') as f:
    s = f.read()
setrecursionlimit(20000)
inp = list(map(int, s.split()))
n, m = inp[0], inp[1]
graph = [[] for _ in range(n + 1)]
visited = [False for _ in range(n + 1)]
for i in range(2, len(inp), 2):
    s, e = inp[i], inp[i + 1]
    graph[s].append(e)
    graph[e].append(s)
comps = {}
comp = 1
for i in range(1, n + 1):
    if not visited[i]:
        dfs(graph, visited, i, comp, comps)
        comp += 1
print(comp - 1)
for el in comps:
    print(len(comps[el]))
    print(' '.join(map(str, comps[el])))
