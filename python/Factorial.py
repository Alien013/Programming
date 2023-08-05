def Factorial(n):
    if (n == 1 or n == 0):
        return 1
    else:
        return n*Factorial(n-1)


N = int(input("Enter the number:"))
fact = Factorial(N)
print("Factorial of number is: ", fact)
