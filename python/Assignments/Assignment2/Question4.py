import numpy as np
import pandas as pdd

def independent_ttest(data1, data2, alpha):
	mean1, mean2 = mean(data1), mean(data2)
	se1, se2 = sem(data1), sem(data2)
	sed = sqrt(se1**2.0 + se2**2.0)
	t_stat = (mean1 - mean2) / sed
	df = len(data1) + len(data2) - 2
	cv = t.ppf(1.0 - alpha, df)
	p = (1.0 - t.cdf(abs(t_stat), df)) * 2.0
	return t_stat, df, cv, p