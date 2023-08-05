import numpy as np
import pandas as pd
import scipy.stats as stats
import seaborn as sns
import matplotlib.pyplot as plt
import random

data=stats.norm(loc=0,scale=1).rvs(1000)
ax=sns.distplot(data,bins=20,kde=True,color='blue',hist_kws={"linewidth":15,'alpha':1})
ax.set(xlabel='NORMAL DISTRIBUTION',ylabel='Frequency')
plt.show()

n,prob=10, .6
poisson_data=np.random.poisson(lam=5,size=1000)
ax=sns.distplot(poisson_data,kde=False,color='red')
ax.set(xlabel='POISSON DISTRIBUTION',ylabel='FREQUENCY')
plt.show()