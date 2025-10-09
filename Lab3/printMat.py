def printMatrix(A, starting_index, rows, columns):
    start_row, start_col = starting_index
    print(starting_index)

    for i in range(start_row, start_row + rows):
        for j in range(start_col, start_col + columns):
            print(A[i][j], end=" ")
        print()

matrix = [
    [1,2,3,4,5,6],
    [1,2,3,4,5,6],
    [1,2,3,4,5,6],
    [1,2,3,4,5,6],
    [1,2,3,4,5,6],
    [1,2,3,4,5,6],
]


printMatrix(matrix, (2,3), 4, 2)