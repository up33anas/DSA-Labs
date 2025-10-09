import time
from funcs import RandomArray, MergeSort, writeToCSV

arr = RandomArray(30000)

start = time.time()
MergeSort(arr, 0, len(arr) - 1)
print("Time taken to run:", round(time.time() - start, 6), "seconds")

writeToCSV(arr, "SortedMergeSort.csv")