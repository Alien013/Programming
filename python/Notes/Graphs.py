import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import math

#Continuous Distribution f(x)=1/(b-a)
a = int(input())
b = int(input())
x1 = np.arange(0,100,0.1)
y1 = np.array([1/(b-a) if (i >= a and i <= b) else 0 for i in x1])
plt.plot(x1,y1)

#Normal distribution
a = int(input())
b = int(input())
x2 = np.arange(0,101,0.1)
y2 = np.array([(1/(b*math.sqrt(2*math.pi)))*(math.e**(-0.5*((i-a)/b)**2)) for i in x2])
print(y2)
plt.plot(x2,y2)

#Gamma distribution
a = int(input())
b = int(input())
x3 = np.arange(0,101,0.1)
y3 = np.array([(((b**a)*(i**(a-1))*(math.e**(-(b*i))))/(math.factorial(a-1))) for i in x3])
plt.plot(x3,y3)

#Exponential distribution
a = int(input())
x4 = np.arange(0,101,0.1)
y4 = np.array([a*((math.e)**(-a*i)) for i in x4])
plt.plot(x4,y4)

#poisson distribution
a = int(input())
x5 = np.arange(0,171,1)
y5 = np.array([((math.e**(-a))*(a**i)/(math.factorial(i))) for i in x5])
plt.scatter(x5,y5)