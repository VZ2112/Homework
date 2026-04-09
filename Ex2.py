def transpose(mat): return [[mat[j][i] for j in range(len(mat))] for i in range(len(mat[0]))]

mat = [[1, 2, 3], [4, 5, 6]]
print(transpose(mat))
