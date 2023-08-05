from scipy.stats import chi2
from statsmodels.formula.api import ols
import statsmodels.api as sm
from statsmodels.stats import weightstats as stests
from scipy import stats
import pandas as pd
from scipy.stats import ttest_ind
from cgi import test
import numpy as np
from scipy.stats import ttest_1samp

ages = [21, 23, 21, 24, 43, 45, 65, 53, 43, 23, 21, 65, 54, 43]
print(len(ages))

sum = np.sum(ages)
Mean = sum/len(ages)


# Mean=np.mean(ages)
print("Mean = ", Mean)

Sample_size = 10
Sample = np.random.choice(ages, Sample_size)
print(Sample)

ttest, p_value = ttest_1samp(Sample, 10)
print(Sample)


# T test (one sampled test)

# ages = np.genfromtxt(“ages.csv”)
print(ages)
ages_mean = np.mean(ages)
print(ages_mean)
tset, pval = ttest_1samp(ages, 30)
# print(“p-values”, pval)
if pval < 0.05:    # alpha value is 0.05 or 5%
    print(" we are rejecting null hypothesis")
else:
    print("we are accepting null hypothesis")

# T test (two sampled test)
week1 = np.genfromtxt("week1.csv",  delimiter=",")
week2 = np.genfromtxt("week2.csv",  delimiter=",")
print(week1)
print("week2 data :-\n")
print(week2)
week1_mean = np.mean(week1)
week2_mean = np.mean(week2)
print("week1 mean value:", week1_mean)
print("week2 mean value:", week2_mean)
week1_std = np.std(week1)
week2_std = np.std(week2)
print("week1 std value:", week1_std)
print("week2 std value:", week2_std)
ttest, pval = ttest_ind(week1, week2)
print("p-value", pval)
if pval < 0.05:
    print("we reject null hypothesis")
else:
    print("we accept null hypothesis")

#   Paired sample test
df = pd.read_csv("blood_pressure.csv")
df[['bp_before', 'bp_after']].describe()
ttest, pval = stats.ttest_rel(df['bp_before'], df['bp_after'])
print(pval)
if pval < 0.05:
    print("reject null hypothesis")
else:
    print("accept null hypothesis")


# z test
ztest, pval = stests.ztest(df['bp_before'], x2=None, value=156)
print(float(pval))
if pval < 0.05:
    print("reject null hypothesis")
else:
    print("accept null hypothesis")

# one way Anova test
df_anova = pd.read_csv('PlantGrowth.csv')
df_anova = df_anova[['weight', 'group']]
grps = pd.unique(df_anova.group.values)
d_data = {grp: df_anova['weight'][df_anova.group == grp] for grp in grps}

F, p = stats.f_oneway(d_data['ctrl'], d_data['trt1'], d_data['trt2'])
print("p-value for significance is: ", p)
if p < 0.05:
    print("reject null hypothesis")
else:
    print("accept null hypothesis")

# Two way anova test F test
df_anova2 = pd.read_csv(
    "https://raw.githubusercontent.com/Opensourcefordatascience/Data-sets/master/crop_yield.csv")
model = ols('Yield ~ C(Fert)*C(Water)', df_anova2).fit()
print(
    f"Overall model F({model.df_model: .0f},{model.df_resid: .0f}) = {model.fvalue: .3f}, p = {model.f_pvalue: .4f}")
res = sm.stats.anova_lm(model, typ=2)
res

# Chi_Square Test
f_chi = pd.read_csv('chi-test.csv')
contingency_table = pd.crosstab(df_chi["Gender"], df_chi["Shopping?"])
print('contingency_table :-\n', contingency_table)
# Observed Values
Observed_Values = contingency_table.values
print("Observed Values :-\n", Observed_Values)
b = stats.chi2_contingency(contingency_table)
Expected_Values = b[3]
print("Expected Values :-\n", Expected_Values)
no_of_rows = len(contingency_table.iloc[0:2, 0])
no_of_columns = len(contingency_table.iloc[0, 0:2])
ddof = (no_of_rows-1)*(no_of_columns-1)
print("Degree of Freedom:-", ddof)
alpha = 0.05
chi_square = sum(
    [(o-e)**2./e for o, e in zip(Observed_Values, Expected_Values)])
chi_square_statistic = chi_square[0]+chi_square[1]
print("chi-square statistic:-", chi_square_statistic)
critical_value = chi2.ppf(q=1-alpha, df=ddof)
print('critical_value:', critical_value)
# p-value
p_value = 1-chi2.cdf(x=chi_square_statistic, df=ddof)
print('p-value:', p_value)
print('Significance level: ', alpha)
print('Degree of Freedom: ', ddof)
print('chi-square statistic:', chi_square_statistic)
print('critical_value:', critical_value)
print('p-value:', p_value)
if chi_square_statistic >= critical_value:
    print("Reject H0,There is a relationship between 2 categorical variables")
else:
    print("Retain H0,There is no relationship between 2 categorical variables")

if p_value <= alpha:
    print("Reject H0,There is a relationship between 2 categorical variables")
else:
    print("Retain H0,There is no relationship between 2 categorical variables")


def check_normality(data):
    test_stat_normality, p_value_normality = stats.shapiro(data)
    print("p value:%.4f" % p_value_normality)
    if p_value_normality < 0.05:
        print("Reject null hypothesis >> The data is not normally distributed")
    else:
        print("Fail to reject null hypothesis >> The data is normally distributed")


sync = np.array([94., 84.9, 82.6, 69.5, 80.1, 79.6, 81.4, 77.8, 81.7, 78.8, 73.2,
                 87.9, 87.9, 93.5, 82.3, 79.3, 78.3, 71.6, 88.6, 74.6, 74.1, 80.6])
asyncr = np.array([77.1, 71.7, 91., 72.2, 74.8, 85.1, 67.6,
                  69.9, 75.3, 71.7, 65.7, 72.6, 71.5, 78.2])
check_normality(sync)
check_normality(asyncr)


def check_variance_homogeneity(group1, group2):
    test_stat_var, p_value_var = stats.levene(group1, group2)
    print("p value:%.4f" % p_value_var)
    if p_value_var < 0.05:
        print("Reject null hypothesis >> The variances of the samples are different.")
    else:
        print("Fail to reject null hypothesis >> The variances of the samples are same.")
