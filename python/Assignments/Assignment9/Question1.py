import pandas as pd
import matplotlib.pyplot as plt
from sklearn.cluster import KMeans

dataset = {(0.40, 0.22, 0.35, 0.26, 0.08, 0.45),
           (0.53, 0.38, 0.32, 0.19, 0.41, 0.30)}

df = pd.DataFrame(dataset)
print(dataset)

dataset_new = dataset[['X', 'Y']].values
limit = int((dataset_new.shape[0]//2)**0.5)

wcss = {}
for k in range(2, limit+1):
    model = KMeans(n_clusters=k)
    model.fit(dataset_new)
    wcss[k] = model.inertia_

plt.plot(wcss.keys(), wcss.values(), 'gs-')
plt.xlabel('Values of "k"')
plt.ylabel('WCSS')
plt.show()
