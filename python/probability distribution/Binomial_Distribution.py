import seaborn as sns
import matplotlib.pyplot as plt
import numpy as np
n,prob=10, .6
data=np.random.binomial(n,prob,10000)
ax=sns.distplot(data,bins=20,kde=False,color='blue',hist_kws={"linewidth":15,'alpha':1})
ax.set(xlabel='BINOMIAL DISTRIBUTION',ylabel='FREQUENCY')
plt.show()