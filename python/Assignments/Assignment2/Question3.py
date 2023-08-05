import numpy as np
import pandas as pd
from scipy.stats import chi2_contingency
from scipy.stats import chi2

table1= [[18,36,21,9,6],[12,36,45,36,21], [6,9,9,3,3],[3,9,9,6,3] ]
stat,p,dof,expected = chi2_contingency(table1)
prob = 0.95
critical = chi2.ppf(prob, dof)
if abs(stat) >= critical:
    print('Reject the Null Hypothesis')
else:
    print('Failed to reject the Null Hypothesis')