def sqrt(n: float) -> float:
    """
    Computes the square root of n using Newton's method.
    Does not use math.sqrt or any other math library function.
    """
    if n < 0:
        raise ValueError("sqrt: negative argument")
    if n == 0.0:
        return 0.0
    # Initial approximation
    x = n if n >= 1.0 else 1.0
    for _ in range(100):
        x_new = (x + n / x) / 2.0
        if abs(x_new - x) < 1e-15:
            break
        x = x_new
    return x_new


def polynomial_degree(coeffs: dict[int, float]) -> int:
    """
    Returns the highest exponent with a non-zero coefficient.
    Returns 0 if all coefficients are zero.
    """
    non_zero = [p for p, c in coeffs.items() if c != 0.0]
    return max(non_zero) if non_zero else 0