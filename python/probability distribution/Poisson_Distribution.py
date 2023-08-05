import seaborn as sns
import matplotlib.pyplot as plt
import numpy as np
n,prob=10, .6
poisson_data=np.random.poisson(lam=5,size=1000)
ax=sns.distplot(poisson_data,kde=False,color='blue')
ax.set(xlabel='POISSON DISTRIBUTION',ylabel='FREQUENCY')
plt.show()