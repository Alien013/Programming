import numpy as np
a=np.array([3,4,5,6,7])
b=np.array([3,4,5,6,7])
print(a)

print(a+2)
print(a-2)
print(a*2)
print(a%2)
print(a/2)
print(a+b)
print(a*b)
print(np.sin(a))
print(np.cos(a))
print(np.tan(a))

# Matrix multiplication
c=np.random.rand(3,3)
d=np.random.rand(3,3)
print(np.matmul(c,d))

# To find determinant 
print(np.linalg.det(c))

# Eigen value of matrix
print(np.linalg.eig(c))


print(np.min(a)) # Minimum of maatrix

print(np.min(c, axis=1)) # Minimum of each rows of  maatrix
print(np.min(c, axis=0)) # Minimum of each columns of maatrix

print(np.max(c, axis=0)) # Minimum of each columns of maatrix
print(np.max(c, axis=1)) # Minimum of each rows of maatrix

print(np.sum(c, axis=1)) # sum of each rows of maatrix
print(np.sum(c, axis=0)) # sum of each rows of maatrix

# Statistic operation- mean,median,standard deviation , variance
print(np.mean(a))
print(np.median(a))
print(np.std(a))
print(np.var(a))

# solving linear equation
# 4x + 5y = 13
# 5 - 3 = 7
coefficient1=np.array([[4,5],[5,-3]])
coefficient2=np.array([13,7])
print(np.linalg.solve(coefficient1,coefficient2))

