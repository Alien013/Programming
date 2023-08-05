# add numpy library
from secrets import randbelow
import numpy as np

# Creating 1D array
a=np.array([1,2,3,4,5])
print(a)

# Creating 2D array
b=np.array([[1,2,3,4],[1,2,3,4]])
print(b)

# To get dimension of an array
print(a.ndim)
print(b.ndim)

# To get the shape 
print(a.shape)
print(b.shape)

# change the shape or reshape
c=np.array([1,2,3,4,5,6,7,8])
print(c)
d=c.reshape(2,4)
print(d)

print(a.itemsize) # TO KNOW THE SIZE OF EEACH ELEMENT
print(b.itemsize)

print(a.dtype) # TO GET TOTAL BYTES USED 
print(b.dtype)

# TO GET TOTAL NO. OF BYTES
print(a.nbytes)
print(b.nbytes)

# tO GET TOTAL NUMBER OF ELEMENTS
print(a.size)
print(b.size)

# Axxessing and chamging specific element
e=np.array([[1,2,3,4,5,6,7],[8,9,10,11,12,13,14]])
print(e)
print(e[0,5])
print(e[0,:])
print(e[:,0])
print(e[0,1:6:2])

e[0,0]=20 # to change value of any position
print(e)

# 3D-arrayb using numpy 
f=np.array([[[1,2,3],[4,5,6]],[[7,8,9],[1,2,3]]])
print(f)
print(f[0,:,:])

# Creating NULL matrix
print(np.zeros((3,3),dtype='int32'))

# Creating ones matrix
print(np.ones((3,3),dtype='int32'))

# To update any given matrix from any number
print(np.full_like(f,10))

# Creating random number array
print(np.random.rand(2,4))

# Creating array of random integer values of given size
print(np.random.randint(1,9, size=(4,4)))

# Creating identity matrix
print(np.identity(3, dtype='int32' ))