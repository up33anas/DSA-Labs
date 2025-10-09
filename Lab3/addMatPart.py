def MatAddPartial(A, B, start, size):
    start_row = start[0]
    start_col = start[1]
    end_row = start_row + size
    end_col = start_col + size
    sumMatrix = [[0 for _ in range(size)] for _ in range(size)]

    for i in range(start_row, end_row):
        for j in range(start_col, end_col):
            sumMatrix[i-1][j-1] = A[i][j] + B[i][j]

    return sumMatrix

mat1 = [
    [1,2,3,4],
    [5,6,7,8],
    [10,10,10,10]
]

mat2 = [
    [-1,-2,99,-4],
    [-5,-6,-7,-8],
    [12,12,12,12]
]

print(MatAddPartial(mat1, mat2, (0,1), 2))