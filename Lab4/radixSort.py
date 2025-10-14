def CountingSortForRadix(input, exp):
    n = len(input)
    output = [0] * n
    count = [0] * 10

    for i in range(n):
        index = (input[i] // exp) % 10 
        count[index] += 1

    for i in range(1, 10):
        count[i] += count[i - 1]

    for i in range(n - 1, -1, -1):
        index = (input[i] // exp) % 10
        count[index] -= 1
        output[count[index]] = input[i]

    for i in range(n):
        input[i] = output[i]

def RadixSort(arr):
    max_val = max(arr)
    exp = 1

    while max_val // exp > 0:
        CountingSortForRadix(arr, exp)
        exp *= 10

arr = [170, 45, 75, 90, 802, 24, 2, 66]
RadixSort(arr)
print(arr)