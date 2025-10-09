from funcs import SearchA

# Driver
X = [22,2,1,7,11,13,5,2,9]
num = int(input("Enter the number: "))
array  = SearchA(X, num)
    
n = len(array)

print("Index:", end=" ") if n else print("Entered number not found", end="")

for i in range(n):
    print(array[i], end="")
    if i < n-1: print(",", end="")
print()