import json


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


def get_mileage(X_min, X_max):
    while True:
        mileage_input = input("Enter mileage of the car: ")
        try:
            mileage = float(mileage_input)
            if mileage < 0:
                print("Error: mileage cannot be negative. Please try again.")
            else:
                if mileage < X_min or mileage > X_max:
                    print(f"Warning: {mileage:.0f} km is outside the training range "
                          f"({X_min:.0f}–{X_max:.0f} km). Prediction may be less accurate.")
                return mileage
        except ValueError:
            print("Error: please enter a valid number.")


def predict():
    params, trained = load_params()

    if not trained:
        print("Warning: model has not been trained yet (model_params.json not found).")
        print("theta0 and theta1 are set to 0. Run ModelTraining.py first to train the model.\n")
        theta0, theta1, X_max, X_min, Y_max = 0, 0, 1, 0, 1
    else:
        theta0 = params["theta0"]
        theta1 = params["theta1"]
        X_max  = params["X_max"]
        X_min  = params.get("X_min", 0)
        Y_max  = params["Y_max"]

    mileage = get_mileage(X_min, X_max)
    price = estimate_price(mileage, theta0, theta1, X_max, Y_max)

    print(f"Estimated price for {mileage:.0f} km: ${price:.0f}")


if __name__ == "__main__":
    predict()
