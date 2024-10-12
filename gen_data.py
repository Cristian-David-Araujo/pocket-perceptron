import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

from sklearn.model_selection import train_test_split
from sklearn import datasets
# After generating your dataset
X, y = datasets.make_blobs(n_samples=1000, n_features=2, centers=2, cluster_std=2.5, random_state=100)

# Create a DataFrame
data = pd.DataFrame(X, columns=["Feature 1", "Feature 2"])
data["Label"] = y

# Save to CSV
data.to_csv("classification_data.csv", index=False)