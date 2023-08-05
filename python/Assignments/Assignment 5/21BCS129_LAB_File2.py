import numpy as np
import pandas as pd
import random
M=int(input('Enter the length of rope in meter:\n'))
N=int(input('Enter number of cuts:\n'))
print(M)
print(N)
cuts=[]
for i in range(N):
    cuts.append(int(input()))
T=int(input("Checker T:"))

answer=0
for i in range(len(cuts)):
    for j in range(i+1,N):
        if i !=j and abs(cuts[i] - cuts[j] >= T):
            answer+=1
Probability=int(answer/N)
print("Probability+",Probability)
