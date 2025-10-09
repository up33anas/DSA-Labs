from funcs import ColumnWiseSum, RowWiseSum
        
# Driver
arr = [
    [1, 13, 13],
    [5, 11, 6],
    [4, 4, 9]
]

columnWiseSumArr = ColumnWiseSum(arr)
rowWiseSumArr = RowWiseSum(arr)

print("\t ",rowWiseSumArr[0])
print("Row-wise:", rowWiseSumArr[1])
print("\t ", rowWiseSumArr[2])

print("Column-wise:", end=" ")
for i in range(len(columnWiseSumArr)):
    print(columnWiseSumArr[i], end=" ")
print()