def top_sorted(graph):
    res = [i for i in range(len(graph))]
    for i in range(1, len(graph) - 1):
        for j in range(i):
            if res[j + 1] in graph[res[j]]:
                tmp = res[j]
                res[j] = res[j + 1]
                res[j + 1] = tmp
    return res

def longest_path(graph):
    mx = -1
    res = []
    sequitur = {}
    lgts = {}
    srtd = top_sorted(graph)
    for i in srtd:
        lgts[i] = 0
        for j in graph[i].keys():
            if lgts[j] + graph[i][j] > lgts[i]:
                sequitur[i] = j
                lgts[i] = lgts[j] + graph[i][j]
        if mx not in lgts or lgts[i] > lgts[mx]:
            mx = i
    res.append(mx)
    while mx in sequitur:
        mx = sequitur[mx]
        res.append(mx)
    return res

graph = [
    {},
    {0: 2},
    {1: 5},
    {2: 20},
    {2: 10},
    {1: 30}
]

print(longest_path(graph))
