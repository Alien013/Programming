import numpy as np
import pandas as pd
import random

S=input('Enter the string:\n')
L= len(S)
print(L)
N=int(input('Enter an Integer:\n'))
print(S)
total=L*L
SampleA=[]
SampleB=[]
difference=[]
for i in range(L):
    for j in range(L):
        SampleA.append(S[i])
        SampleB.append(S[j])
        difference.append(abs(i-j))
        df=pd.DataFrame({'Sample i':SampleA,'Sample j':SampleB,'abs(i-j)':difference})
        print(df)
count=0
for k in range(len(df)):
    if SampleA[k]==SampleB[k] and SampleA[k]!='y' and difference[k]<=N:
        count+=1
print(count)
print("Probability=",count,"/",total)    