def MatMul(A, B):
    rows_of_A = len(A)
    cols_of_A = len(A[0])
    rows_of_B = len(B)
    cols_of_B = len(B[0])

    # Check dimensions
    assert cols_of_A == rows_of_B, "Matrix dimensions must match"

    # Initialize result with zeros
    result = [[0 for _ in range(cols_of_B)] for _ in range(rows_of_A)]

    for i in range(rows_of_A):
        for j in range(cols_of_B):
            for k in range(cols_of_A):
                result[i][j] += A[i][k] * B[k][j]

    return result

mat1 = [
    [1,2,3],
    [2,2,2]
]

mat2 = [
    [2,1],
    [0,0],
    [3,3]
]

print(MatMul(mat1,mat2))