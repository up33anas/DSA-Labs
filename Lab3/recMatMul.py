def multiply_recursive(A, B, C, rowA, colA, colB, i, j, k):
    if i >= rowA:
        return

    if j < colB:
        if k < colA:
            C[i][j] += A[i][k] * B[k][j]
            multiply_recursive(A, B, C, rowA, colA, colB, i, j, k + 1)
        else:
            # move to next column
            multiply_recursive(A, B, C, rowA, colA, colB, i, j + 1, 0)
    else:
        # move to next row
        multiply_recursive(A, B, C, rowA, colA, colB, i + 1, 0, 0)

def multiply_matrix(A, B):
    rowA, colA = len(A), len(A[0])
    rowB, colB = len(B), len(B[0])

    if colA != rowB:
        raise "Matrix multiplication not possible: dimensions mismatch"

    # initialize result matrix
    C = [[0 for _ in range(colB)] for _ in range(rowA)]

    multiply_recursive(A, B, C, rowA, colA, colB, 0, 0, 0)

    return C

# Example
A = [[1, 2, 3],
     [-2, 5, 6],
     [7, 8, 9]]

B = [[4, 2, 2],
     [1, 0, 6],
     [5, 8, 9]]

C = multiply_matrix(A, B)

for row in C:
    print(row)
