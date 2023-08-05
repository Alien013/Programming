# p=float(input("Enter the principal amount:"))
# r=float(input("Enter the rate of interest:"))
# t=float(input("Enter the time:"))
# SI = (p*r*t)/100
# print("Simpple Interest is: ",SI)

p = float(input("Enter the principal: "))
r = float(input("Enter the rate of interest: "))
t = float(input("Enter the time: "))
Amount = p*((1+r/100)**t)
CI = Amount-p
print("Compound Interest: ", CI)
