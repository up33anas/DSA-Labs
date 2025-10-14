import math

def InsertionSort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key
    return arr

def BucketSort(A: list):
    assert all(isinstance(x, (float, int)) for x in A), "All list elements must be numbers"
    assert all(0 <= x < 1 for x in A), "Values must be in range [0, 1)"

    n = len(A)
    B = [[] for _ in  range(n)]

    for i in range(n):
        B[math.floor(n * A[i])].append(A[i])

    for b in B: InsertionSort(b)

    index = 0
    for b in B:
        for num in b:
            A[index] = num
            index += 1

arr = [0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434] 

BucketSort(arr)
print(arr)