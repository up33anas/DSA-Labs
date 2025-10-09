import time
from funcs import RandomArray, BubbleSort, writeToCSV

arr = RandomArray(30000)

start = time.time()
BubbleSort(arr, 0, len(arr))
print("Time taken to run:", round(time.time() - start, 6), "seconds")

writeToCSV(arr, "SortedBubbleSort.csv")
