import numpy as np

avg= float(input("Average sales according to pas sales data"))
Sample=int(input("Enter the sample size of salesmen: "))
SD=input("Standard deviation of the student: ")
sample_avg=float(input("Enter the sample average sales of salesmen: "))

z= (avg-sample_avg)/(float(SD)/ float(Sample**(0.5)))

alpha=1.96

if z>alpha:
    print("Accept null hypothesis. ")
    print("Yes, the training helped. ")
else:
    print("Reject null hypothesis.")
    print("No, training didn't help.")
