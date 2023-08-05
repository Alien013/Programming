import pandas as pd

# Printing dataframes
df = pd.read_csv('G:/My Drive/python/Python/Practice program/Pandas/Data.csv')
print(df)

print(df.shape)

print(df.info())  # To get all information of dataframes


print(df.head(11))  # Print first n rows
print('\n')
print(df.tail(10))  # Print first n columns
