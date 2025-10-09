import random, csv


# Generate a random array
def RandomArray(size):
    return [random.randint(0, 100000) for _ in range(size)]

# Insertion sort
def InsertionSort(array, start, end):
    for i in range(start + 1, end):
        key = array[i]
        j = i - 1
        while j >= start and array[j] > key:
            array[j + 1] = array[j]
            j -= 1
        array[j + 1] = key
    return array

# Merge Sort
def Merge(array, p, q, r):
    mergedArray = [] # empty temp array

    # p = start, q = mid, r = end
    i, j = p, q + 1 

    # merge the array
    while i <= q and j <= r:
        if array[i] <= array[j]:
            mergedArray.append(array[i])
            i += 1
        else: 
            mergedArray.append(array[j])
            j += 1
    
    # append the remaining elements of any array
    while i <= q:
        mergedArray.append(array[i])
        i += 1
    while j <= r:
        mergedArray.append(array[j])
        j += 1

    # copy temp array to the original one
    for i in range(len(mergedArray)):
        array[i + p] = mergedArray[i]
        
def MergeSort(array, start, end):
    if start < end: 
        mid = start + (end - start) // 2

        MergeSort(array, start, mid)
        MergeSort(array, mid + 1, end)

        # merge two sorted parts
        Merge(array, start, mid, end)

# Hybrid Merge Sort
def HybridMergeSort(array, start, end, k):
    if end - start + 1 <= k:       # size of this slice <= k
        InsertionSort(array, start, end + 1)  # end is exclusive in our InsertionSort
        return 

    if start < end: 
        mid = start + (end - start) // 2

        HybridMergeSort(array, start, mid, k)
        HybridMergeSort(array, mid + 1, end, k)

        # merge two sorted parts
        Merge(array, start, mid, end)

# Bubble Sort
def BubbleSort(array, start, end):
    n = end - start                # length of subarray
    for i in range(n - 1):
        swapped = False
        for j in range(start, end- i - 1):
            if array[j] > array[j + 1]:
                array[j], array[j + 1] = array[j + 1], array[j]
                swapped = True
        if not swapped:
            break
    return array

# Selection Sort
def SelectionSort(array, start, end):
    for i in range(start, end - 1):
        minIndex = i 
        for j in range(i + 1, end):
            if array[j] < array[minIndex]:
                minIndex = j
        array[i], array[minIndex] = array[minIndex], array[i]
    return array

# Write data to csv file
def writeToCSV(arr, filename):
    with open(filename, 'w', newline="") as file:
        writer = csv.writer(file)
        for item in arr:
            writer.writerow([item])

# Shuffle the letters in a word
# def ShuffleArray(array, start, end):
#     subArr = array[start:end]
#     random.shuffle(subArr)
#     array[start:end] = subArr
def ShuffleArray(array, start, end):
    """Shuffle array[start:end] in place."""
    sub = array[start:end]
    random.shuffle(sub)
    array[start:end] = sub