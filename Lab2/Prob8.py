import time
from funcs import InsertionSort, MergeSort, ShuffleArray

# 1. Read all words
with open("words.txt", "r", encoding="utf-8") as f:
    words = f.read().split()

# 2. First round (original order)
arr1 = words.copy()
start = time.perf_counter()
InsertionSort(arr1, 0, len(arr1) - 1)
t_ins1 = time.perf_counter() - start

arr2 = words.copy()
start = time.perf_counter()
MergeSort(arr2, 0, len(arr2) - 1)
t_mer1 = time.perf_counter() - start

print(f"Initial InsertionSort: {t_ins1:.6f} seconds")
print(f"Initial MergeSort:     {t_mer1:.6f} seconds")

# 3. Shuffle and second round
shuffled = words.copy()
ShuffleArray(shuffled, 0, len(shuffled) - 1)

arr3 = shuffled.copy()
start = time.perf_counter()
InsertionSort(arr3, 0, len(arr3) - 1)
t_ins2 = time.perf_counter() - start

arr4 = shuffled.copy()
start = time.perf_counter()
MergeSort(arr4, 0, len(arr4) - 1)
t_mer2 = time.perf_counter() - start

print(f"After shuffle InsertionSort: {t_ins2:.6f} seconds")
print(f"After shuffle MergeSort:     {t_mer2:.6f} seconds")
