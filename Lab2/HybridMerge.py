import time
from funcs import RandomArray, HybridMergeSort, writeToCSV

arr = RandomArray(30000)

start = time.time()
HybridMergeSort(arr, 0, len(arr) - 1, k=4000)
print("Time taken to run:", round(time.time() - start, 6), "seconds")

writeToCSV(arr, "SortedHybridSort.csv")