import scipy.stats as stats
import seaborn as sns
import matplotlib.pyplot as plt

data=stats.norm(scale=1,loc=0).rvs(1000)
ax=sns.distplot(data,bins=50,kde=True,color='green',hist_kws={"linewidth":15,'alpha':1})
ax.set(xlabel='NORMAL DISTRIBUTION Histogram',ylabel='Frequency')
plt.show()