def top_sorted(graph):
    res = [i for i in range(len(graph))]
    for i in range(1, len(graph) - 1):
        for j in range(i):
            if res[j] in graph[res[j + 1]]:
                tmp = res[j]
                res[j] = res[j + 1]
                res[j + 1] = tmp
    return res

def longest_path(graph, a, b):
    res = []
    sequitur = {}
    lgts = {}
    srtd = top_sorted(graph)
    srtd = srtd[(srtd.index(a)):]
    lgts[b] = float("inf")
    lgts[a] = 0
    for i in srtd:
        for j in graph[i].keys():
            if j not in lgts: lgts[j] = float("inf")
            if lgts[i] + graph[i][j] < lgts[j]:
                sequitur[j] = i
                lgts[j] = lgts[i] + graph[i][j]
    if lgts[b] < 0: return res
    res.append(b)
    while b != a:
        b = sequitur[b]
        res.append(b)
    res.reverse()
    return res

graph = [
    {1: 8, 2: 10, 3: 14},
    {2: 25, 4: 5},
    {3: 3, 4: 2},
    {5: 18},
    {5: 10},
    {}
]

a, b = 0, 3

print(longest_path(graph, a, b))
