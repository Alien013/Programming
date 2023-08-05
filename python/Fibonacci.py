N = int(input("How many terms? "))
n1 = 0
n2 = 1
sum = 0
if N <= 0:
    print("Please enter a positive integer")
elif N == 1:
    print("Fibonacci sequence upto", N, ":")
    print(n1)
else:
    print("Fibonacci sequence:")
    while sum < N:
        print(n1)
        nth = n1 + n2
        n1 = n2
        n2 = nth
        sum += 1
