def mat_prod(mat, vec):
    res = []
    if len(mat[0]) != len(vec): return -1
    for i in range(len(mat)):
        res.append(0)
        for j in range(len(vec)):
            res[i] += mat[i][j] * vec[j]
    return res

mat = [[1, 2], [2, 4]]
vec = [1, 2]
print(mat_prod(mat, vec))
