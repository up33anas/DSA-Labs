def add_matrices(A, B):
    n = len(A)
    return [[A[i][j] + B[i][j] for j in range(n)] for i in range(n)]

def subtract_matrices(A, B):
    n = len(A)
    return [[A[i][j] - B[i][j] for j in range(n)] for i in range(n)]

def split_matrix(M):
    n = len(M)
    mid = n // 2

    # Sub-matrices
    M11 = [row[:mid] for row in M[:mid]]
    M12 = [row[mid:] for row in M[:mid]]
    M21 = [row[:mid] for row in M[mid:]]
    M22 = [row[mid:] for row in M[mid:]]

    return M11, M12, M21, M22

def MatMulStrassen(A, B):    
    if len(A) == 1:  return [[A[0][0] * B[0][0]]]

    # Make sub-matrices
    A11, A12, A21, A22 = split_matrix(A)
    B11, B12, B21, B22 = split_matrix(B)

    M1 = MatMulStrassen(add_matrices(A11, A22), add_matrices(B11, B22)) # M1 = (A11 + A22)(B11 + B22)
    M2 = MatMulStrassen(add_matrices(A21, A22), B11) # M2 = (A21 + A22)(B11)
    M3 = MatMulStrassen(A11, subtract_matrices(B12, B22)) # M3 = (A11)(B12 – B22)
    M4 = MatMulStrassen(A22, subtract_matrices(B21, B11)) # M4 = (A22)(B21 – B11)
    M5 = MatMulStrassen(add_matrices(A11, A12), B22) # M5 = (A11 + A12)(B22)
    M6 = MatMulStrassen(subtract_matrices(A21, A11), add_matrices(B11, B12)) # M6 = (A21 – A11)(B11 + B12)
    M7 = MatMulStrassen(subtract_matrices(A12, A22), add_matrices(B21, B22)) # M7 = (A12 – A22)(B21 + B22)

    C11 = add_matrices(subtract_matrices(add_matrices(M1, M4), M5), M7) # C11 = ((M1 + M4) - M5) * M7
    C12 = add_matrices(M3, M5) # C12 = M3 + M5
    C21 = add_matrices(M2, M4) # C21 = M2 + M4
    C22 = add_matrices(subtract_matrices(add_matrices(M1, M3), M2), M6) # C22 = ((M1 + M2) - M2) * M6

    new_matrix = []
    for i in range(len(C11)):
        new_matrix.append(C11[i] + C12[i])
    for i in range(len(C21)):
        new_matrix.append(C21[i] + C22[i])

    return new_matrix


A = [[1, 2], 
     [3, 4]]

B = [[5, 6], 
     [7, 8]]

print("Strassen Multiplication Result:")
for row in MatMulStrassen(A, B):
    print(row)
