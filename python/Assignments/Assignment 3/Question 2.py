import numpy as np
import pandas as pd
import itertools

total=(int)(input("Enter the total number of variables:"))
outcomes=[list(itertools.product('HT',repeat =total))]
sample=2**total
print(outcomes)

expectationX=0
for i in range(total+1):
    fav_outcomes=[flip_outcomes for flip_outmes in outcomes iflen(list(itertools.filterfalse(lambda x:x=='H',flip_outcomes for flip_outcomes in outcomes if len(itertools.itertools.filterfalse(lambda y : y=='T')))))]
    probab= len(fav_outcomes)/sample
    print(i,probab)  