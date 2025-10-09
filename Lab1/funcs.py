#
def SearchA(Arr, x):
    arr_of_indices = []
    for i in range(len(Arr)):
        if Arr[i] == x:
            arr_of_indices.append(i)
    return arr_of_indices

#
def SearchB(Arr, x):
    arr_of_indices = []
    for i in range(len(Arr)):
        if Arr[i] == x:
            arr_of_indices.append(i) 
        if Arr[i+1] > x: break
    return arr_of_indices

#
def Minimum(Arr, starting, ending):
    minIndex = starting
    minVal = Arr[starting]
    for i in range(starting, ending + 1):
        if Arr[i] < minVal:
            minVal = Arr[i]
            minIndex = i
    return minIndex

#
def Sort4(arr):
    arr = arr[:]
    newArr = []
    while arr:
        minIndex = Minimum(arr, 0, len(arr)-1)
        newArr.append(arr[minIndex])
        arr.pop(minIndex)
    return newArr

#
def StringReverse(str, starting, ending):
    if starting == ending: return 
    StringReverse(str, starting+1, ending)
    print(str[starting], end="")

#
def SumIterative(number):
    sum = 0
    while number > 0:
        sum += number%10
        number = int(number/10)
    return sum

def SumRecursive(number):
    if number <= 0: return 0
    return number%10 + SumRecursive(int(number/10))

#
def ColumnWiseSum(Mat):
    sumArr = []
    for i in range(len(Mat[0])):
        sum = 0
        for j in range(len(Mat)):
            sum += Mat[j][i]
        sumArr.append(sum)
    return sumArr

def RowWiseSum(Mat) :
    sumArr = []
    for i in range(len(Mat)):
        sum = 0
        for j in range(len(Mat[0])):
            sum += Mat[i][j]
        sumArr.append(sum)
    return sumArr

#
def SortedMerge(Arr1, Arr2):
    mergedArr = []
    for i in range(len(Arr1)):
        for j in range(len(Arr2)):
            if Arr1[i] <= Arr2[j]:
                mergedArr.append(Arr1[i])
                if i < len(Arr1) - 1:
                    if Arr1[i+1] > Arr2[j]:
                        mergedArr.append(Arr2[j])
                break
    if len(Arr1)>len(Arr2):
        greaterArr = Arr1 
    elif len(Arr1) != len(Arr2):
        greaterArr = Arr2
    for i in range(len(greaterArr)):
        if greaterArr[i] >= mergedArr[len(mergedArr)-1]:
            mergedArr.append(greaterArr[i])
    return mergedArr

#
def PalindromRecursive(str):
    if len(str) == 0 or len(str) == 1: return True
    if str[0] == str[-1]: return PalindromRecursive(str[1:-1])
    else: return False

#
def Sort10(Arr):
    positiveArr = []
    negativeArr = []
    newArr = []
    for i in range(len(Arr)):
        if Arr[i] >= 0:
            positiveArr.append(Arr[i])
        else: negativeArr.append(Arr[i])
    positiveArr = Sort4(positiveArr)
    negativeArr = Sort4(negativeArr)

    maxLen = len(negativeArr) if len(negativeArr) > len(positiveArr) else len(positiveArr)
    for i in range(maxLen):
        if i < len(negativeArr):
            newArr.append(negativeArr[i])
        if i < len(positiveArr):
            newArr.append(positiveArr[i])
    return newArr