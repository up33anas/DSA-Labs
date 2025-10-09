def MatAdd(A,B):
    rows = len(A)
    cols = len(A[0])
    sumMatrix = [[0 for _ in range(cols)] for _ in range(rows)]

    for i in range(rows):
        for j in range(cols):
            sumMatrix[i][j] = A[i][j] + B[i][j]
    
    return sumMatrix

mat1 = [
    [1,2,3,4],
    [5,6,7,8]
]

mat2 = [
    [-1,-2,99,-4],
    [0,0,0,0]
]

print(MatAdd(mat1, mat2))