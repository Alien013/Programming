print("Enter average daily intake of dairy products: ")
X= int(input())
print("Enter the standard deviation: ")
SD=int(input())
print("Enter the N: ")
n=int(input())

if(n == 0):   
    print("Enter any non-zero value!")
else:
    print("Range for 95% confident = ",X-1.96*SD/(n**(0.5))," to ",X+1.96*SD/(n**(0.5)))
    print("Range for 90% confident = ",X-1.645*SD/(n**(0.5))," to: ",X+1.645*SD/(n**(0.5)))
    print("Range for 99% confident = ",X-2.58*SD/(n**(0.5))," to ",X+2.58*SD/(n**(0.5)))
