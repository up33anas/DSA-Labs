import time
from funcs import RandomArray, InsertionSort, writeToCSV

# Driver Code
arr = RandomArray(30000)

start = time.time()
InsertionSort(arr, 0, len(arr))
print("Time taken to run:", round(time.time() - start, 6), "seconds")

writeToCSV(arr, "SortedInsertionSort.csv")