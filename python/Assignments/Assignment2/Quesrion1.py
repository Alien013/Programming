import numpy as np

avg= float(input("Enter the average weight"))
SD=input("Standard deviation of the student weight:")

Sample=int(input("Enter the sample size of students: "))
sample_avg=float(input("Enter the sample average weight: "))

z= (float(avg-sample_avg)/(float(SD)/ float(Sample**(0.5))))
alpha=1.95
if z<alpha:
    print("Accept null hypothesis.")
else:
    print("Reject null hypothesis.")
