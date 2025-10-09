import time, csv
from funcs import RandomArray, InsertionSort, MergeSort, HybridMergeSort, SelectionSort, BubbleSort

# Read n values
with open("Nvalues.txt") as f:
    n_values = [int(line.strip()) for line in f if line.strip()]

headers = [
    "Value of n",
    "Insertion Sort (seconds)",
    "Merge Sort (seconds)",
    "Hybrid Merge Sort (seconds)",
    "Selection Sort (seconds)",
    "Bubble Sort (seconds)"
]

def time_sort(func, arr):
    """Return runtime in seconds for a sorting function."""
    start = time.perf_counter()
    func(arr, 0, len(arr) - 1)
    return round(time.perf_counter() - start, 6)

with open("RunTime.csv", "w", newline="", encoding="utf-8") as file:
    writer = csv.writer(file)
    writer.writerow(headers)

    for n in n_values:
        print(f"\nRunning for n = {n:,}")
        base = RandomArray(n)
        row = [n]

        row.append(time_sort(InsertionSort,base.copy() ))
        row.append(time_sort(MergeSort, base.copy()))
        row.append(time_sort(lambda a,l,r: HybridMergeSort(a,l,r,32), base.copy()))
        row.append(time_sort(SelectionSort, base.copy()))
        row.append(time_sort(BubbleSort, base.copy()))

        writer.writerow(row)
        file.flush()

        print("Done:", row)
