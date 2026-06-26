import pandas as pd
import numpy as np
import json


def train():
    data = pd.read_csv("data.csv")
    X = data['km'].to_numpy(dtype=float)
    Y = data['price'].to_numpy(dtype=float)

    X_norm = X / X.max()
    Y_norm = Y / Y.max()

    theta0 = 0
    theta1 = 0
    learningRate = 0.1
    epochs = 1000
    m = len(X_norm)

    # Gradient descent loop
    for _ in range(epochs):
        Y_pred = theta0 + theta1 * X_norm
        error = Y_pred - Y_norm

        tmp_theta0 = learningRate * (1/m) * np.sum(error)
        tmp_theta1 = learningRate * (1/m) * np.sum(error * X_norm)

        theta0 -= tmp_theta0
        theta1 -= tmp_theta1

    params = {
        "theta0": theta0,
        "theta1": theta1,
        "X_max": float(X.max()),
        "X_min": float(X.min()),
        "Y_max": float(Y.max()),
    }

    with open("model_params.json", "w") as f:
        json.dump(params, f)

    print("Training complete. Parameters saved to model_params.json")


if __name__ == "__main__":
    train()
