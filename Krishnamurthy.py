import math

def is_krishnamurthy(num: int) -> bool:
    """
    Check if a number is a Krishnamurthy (Strong) number.
    """
    temp = num
    total = 0
    
    while temp > 0:
        digit = temp % 10
        total += math.factorial(digit)
        temp //= 10
    
    return total == num

# Driver code
if __name__ == "__main__":
    n = int(input("Enter a number: "))
    if is_krishnamurthy(n):
        print(f"{n} is a Krishnamurthy number ✅")
    else:
        print(f"{n} is NOT a Krishnamurthy number ❌")
