import json
import math
import pandas as pd
import matplotlib.pyplot as plt


# ──────────────────────────────────────────────
#  Загрузка параметров модели
# ──────────────────────────────────────────────

def load_params():
    try:
        with open("model_params.json", "r") as f:
            params = json.load(f)
        return params, True
    except FileNotFoundError:
        return None, False


def estimate_price(mileage, theta0, theta1, X_max, Y_max):
    mileage_norm = mileage / X_max
    price_norm = theta0 + theta1 * mileage_norm
    return max(0, price_norm * Y_max)


# ──────────────────────────────────────────────
#  Задание 1: Визуализация данных и линии регрессии
# ──────────────────────────────────────────────

def plot_regression(data, params):
    X = data['km'].to_numpy(dtype=float)
    Y = data['price'].to_numpy(dtype=float)

    theta0 = params["theta0"]
    theta1 = params["theta1"]
    X_max  = params["X_max"]
    Y_max  = params["Y_max"]

    # Линия регрессии: от min до max по X
    x_line = [X.min(), X.max()]
    y_line = [estimate_price(x, theta0, theta1, X_max, Y_max) for x in x_line]

    plt.figure(figsize=(9, 6))
    plt.scatter(X, Y, color="#4C72B0", alpha=0.8, edgecolors="white",
                linewidths=0.5, s=70, label="Training data")
    plt.plot(x_line, y_line, color="#DD4444", linewidth=2, label="Linear regression")

    plt.title("Car Price vs Mileage", fontsize=14, fontweight="bold")
    plt.xlabel("Mileage (km)", fontsize=12)
    plt.ylabel("Price ($)", fontsize=12)
    plt.legend(fontsize=11)
    plt.tight_layout()
    plt.savefig("regression_plot.png", dpi=150)
    plt.show()
    # plt.close()
    print("Plot saved to regression_plot.png")


# ──────────────────────────────────────────────
#  Задание 2: Точность алгоритма
# ──────────────────────────────────────────────

def calculate_precision(data, params):
    X = data['km'].to_numpy(dtype=float)
    Y = data['price'].to_numpy(dtype=float)

    theta0 = params["theta0"]
    theta1 = params["theta1"]
    X_max  = params["X_max"]
    Y_max  = params["Y_max"]

    Y_pred = [estimate_price(x, theta0, theta1, X_max, Y_max) for x in X]

    n = len(Y)
    Y_mean = sum(Y) / n

    # MAE — средняя абсолютная ошибка
    mae = sum(abs(y - yp) for y, yp in zip(Y, Y_pred)) / n

    # RMSE — корень из среднеквадратичной ошибки
    rmse = math.sqrt(sum((y - yp) ** 2 for y, yp in zip(Y, Y_pred)) / n)

    # R² — коэффициент детерминации (насколько модель объясняет дисперсию)
    ss_res = sum((y - yp) ** 2 for y, yp in zip(Y, Y_pred))
    ss_tot = sum((y - Y_mean) ** 2 for y in Y)
    r2 = 1 - ss_res / ss_tot if ss_tot != 0 else 0.0

    print("\n── Model Precision ─────────────────────────")
    print(f"  MAE  (Mean Absolute Error)   : ${mae:>10.2f}")
    print(f"  RMSE (Root Mean Squared Error): ${rmse:>9.2f}")
    print(f"  R²   (Coefficient of Det.)   :  {r2:>9.4f}  ({r2 * 100:.2f}%)")
    print("─────────────────────────────────────────────")

    if r2 >= 0.9:
        quality = "Excellent"
    elif r2 >= 0.7:
        quality = "Good"
    elif r2 >= 0.5:
        quality = "Moderate"
    else:
        quality = "Poor"

    print(f"  Model quality: {quality}")
    print("─────────────────────────────────────────────\n")


# ──────────────────────────────────────────────
#  Точка входа
# ──────────────────────────────────────────────

def main():
    data = pd.read_csv("data.csv")

    params, trained = load_params()
    if not trained:
        print("Error: model_params.json not found. Run ModelTraining.py first.")
        return

    print("=== Bonus: Visualization & Precision ===\n")
    calculate_precision(data, params)
    plot_regression(data, params)


if __name__ == "__main__":
    main()
