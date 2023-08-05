import numpy as np
import pandas as pd
import random
import matplotlib.pyplot as plt
import scipy.stats as stats
uniform_data=stats.uniform.rvs(size=20,scale=10)
pd.DataFrame(uniform_data).plot(kind="density",figsize=(9,9),xlim=(-1,11));
stats.uniform.cdf(x=0.2,loc=0,scale=10)
stats.uniform.ppf(q=0.4,loc=0,scale=10)
plt.show()
for x in range(-1,12,3):
    print("Density at x value"+ str(x))
    print(stats.uniform.pdf(x,loc=0,scale=10))
random.randint(0,10)
import random
random.randint(0,10)
random.random()
random.uniform(0,10)
random.seed(12)
print([random.uniform(0,10) for x in range(4)])
random.seed(12)
print([random.uniform(0,10) for x in range(4)])
prob_under_minus1=stats.norm.cdf(x=-1,loc=0,scale=1)
prob_over_1=1-stats.norm.cdf(x=1,loc=0,scale=1)
prob_between=1-(prob_under_minus1+prob_over_1)
print(prob_under_minus1, prob_over_1, prob_between)

from numpy import random
import matplotlib.pyplot as plt
import seaborn as sns

sns.distplot(random.uniform(size=1000), hist=True)
plt.show()