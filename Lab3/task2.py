import pandas as pd
import numpy as np

# Euclidean distance
def euclidean_distance(a, b):
    return np.sqrt(np.sum((a - b) ** 2))

# Load data
train = pd.read_csv("Train.csv")   # has symptoms + TYPE column
test = pd.read_csv("Test.csv")     # has symptoms only

# Symptoms columns
symptoms = train.columns[:-1]

# Convert to NumPy for speed
X_train = train[symptoms].to_numpy(dtype=float)
y_train = train["TYPE"].to_numpy()
X_test = test[symptoms].to_numpy(dtype=float)

predictions = []

# Loop over test rows
for test_row in X_test:
    # Compute distances to all training rows at once
    distances = np.sqrt(np.sum((X_train - test_row) ** 2, axis=1))
    # Get the nearest neighbor
    nearest_idx = np.argmin(distances)
    predictions.append(y_train[nearest_idx])

# Add predictions to test dataframe
test["Predicted_Label"] = predictions
print(test.head())
