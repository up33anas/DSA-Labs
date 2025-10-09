import random 
from funcs import SumIterative, SumRecursive

# Driver
n = int(input())

# Generates a random number (1 or 2)
function = random.randint(1, 2)

# Calls the function based on the number
print("Sum of digits is:", SumIterative(n) if function == 1 else SumRecursive(n))