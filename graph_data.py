import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

# Load the dataset from CSV
df = pd.read_csv('classification_data.csv')

# Extract features and labels
X = df[['Feature 1', 'Feature 2']].values
y = df['Label'].values

# Split the data (for simplicity, using half as "train" and half as "test")
split_index = int(len(X)*0.7)
X_train, X_test = X[:split_index], X[len(X) - split_index:]
y_train, y_test = y[:split_index], y[len(X) - split_index:]

# Ask for the weights and bias
w1 = float(input("Enter weight w1: "))
w2 = float(input("Enter weight w2: "))
bias = float(input("Enter bias: "))

# Define a simple perceptron model for prediction
def perceptron_predict(x):
    return 1 if np.dot([w1, w2], x) + bias >= 0 else 0

# Define the mesh grid for the decision boundary
def plot_decision_boundary(ax, X, y, title):
    x_min, x_max = X[:, 0].min() - 1, X[:, 0].max() + 1
    y_min, y_max = X[:, 1].min() - 1, X[:, 1].max() + 1

    xx, yy = np.meshgrid(np.arange(x_min, x_max, 0.1),
                         np.arange(y_min, y_max, 0.1))
    Z = np.array([perceptron_predict(x) for x in np.c_[xx.ravel(), yy.ravel()]])
    Z = Z.reshape(xx.shape)

    # Plot the decision boundary
    ax.contourf(xx, yy, Z, alpha=0.1)

    # Scatter plot of actual and predicted data points
    ax.scatter(X[:, 0], X[:, 1], c=y, label='Actual', alpha=1)
    ax.scatter(X[:, 0], X[:, 1], c=[perceptron_predict(x) for x in X], 
               marker='x', label='Predicted', alpha=0.5)

    # Set labels and title
    ax.set_xlabel("Feature 1")
    ax.set_ylabel("Feature 2")
    ax.set_title(title)
    ax.legend()

# Create subplots for training and test data
fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(12, 6))

# Plot decision boundaries for training and test sets
plot_decision_boundary(ax1, X_train, y_train, "Training Data Decision Boundary")
plot_decision_boundary(ax2, X_test, y_test, "Test Data Decision Boundary")

# Display the plot
plt.show()
