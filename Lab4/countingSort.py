def CountingSort(input):
    assert all(isinstance(x, int) for x in input), "List elements must be integers"

    minimum = min(input)
    maximum = max(input)
    range_of_values = maximum - minimum + 1

    count = [0] * range_of_values
    output = [0] * len(input)

    # Shift values to handle negatives
    for num in input:
        count[num - minimum] += 1

    # Cumulative count
    for i in range(1, len(count)):
        count[i] += count[i - 1]

    # Place elements in output (stable)
    for num in reversed(input):
        count[num - minimum] -= 1
        output[count[num - minimum]] = num

    return output

arr = [-5, -10, 0, -3, 8, 5, -1, 10]
ans = CountingSort(arr)
print(ans)
