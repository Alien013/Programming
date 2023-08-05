n1 = int(input("Enter the number: "))
sum = 0
temp = n1
while temp > 0:
    rem = temp % 10
    sum += rem**3
    temp //= 10

if n1 == sum:
    print(n1, "is Armostrang Number")
else:
    print(n1, "is not Armostrang Number")
