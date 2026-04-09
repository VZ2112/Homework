def rot_cw(mat):
    n = len(mat)
    for i in range(n // 2):
        for j in range(i, n - i - 1):
            tmp = mat[i][j]
            mat[i][j] = mat[n - j - 1][i]
            mat[n - j - 1][i] = mat[n - i - 1][n - j - 1]
            mat[n - i - 1][n - j - 1] = mat[j][n - i - 1]
            mat[j][n - i - 1] = tmp

n = int(input("Enter Size of Matrix:"))
mat = [[int(input(f"[{i}][{j}]:")) for j in range(n)] for i in range(n)]

for i in mat: print(i)
print()
rot_cw(mat)
for i in mat: print(i)