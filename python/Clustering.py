from sklearn.datasets import make_blobs
import matplotlib.pyplot as plt
from sklearn.cluster import KMeans
import numpy as np
import pandas as pd
df = pd.read_csv(
    "C:/Users/Manoj Kumar/OneDrive/Desktop/VS Code/python/Assignments/LabExam/new_wine_data.csv")

print("The shape of data is", df.shape)
df.head()

plt.scatter(df['Malic_Acid'], df['Ash'])

wcss = []

for i in range(1, 11):
    km = KMeans(n_clusters=i)
    km.fit_predict(df)
    wcss.append(km.inertia_)
print(wcss)

X = df.iloc[:, :].values
km = KMeans(n_clusters=4)
y_means = km.fit_predict(X)
y_means

plt.plot(range(1, 11), wcss)
plt.plot(range(1, 11), wcss)
X[y_means == 3, 1]

plt.scatter(X[y_means == 0, 0], X[y_means == 0, 1], color='blue')
plt.scatter(X[y_means == 1, 0], X[y_means == 1, 1], color='red')
plt.scatter(X[y_means == 2, 0], X[y_means == 2, 1], color='green')
plt.scatter(X[y_means == 3, 0], X[y_means == 3, 1], color='yellow')


# K-mean on 3D data

centroids = [(-5, -5, 5), (5, 5, -5), (3.5, -2.5, 4), (-2.5, 2.5, -4)]
cluster_std = [1, 1, 1, 1]

X, y = make_blobs(n_samples=200, cluster_std=cluster_std,
                  centers=centroids, n_features=3, random_state=1)
print(X)

import plotly.express as px
fig = px.scatter_3d(x=X[:, 0], y=X[:, 1], z=X[:, 2])
fig.show()
wcss = []
for i in range(1, 21):
    km = KMeans(n_clusters=i)
    km.fit_predict(X)
    wcss.append(km.inertia_)
