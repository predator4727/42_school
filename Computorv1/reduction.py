def reduce_equation(
    left: dict[int, float],
    right: dict[int, float]
) -> dict[int, float]:
    """
    Moves all right-side terms to the left: left - right.
    Returns a dict {exponent: coefficient}.
    """
    all_powers = set(left.keys()) | set(right.keys())
    coeffs: dict[int, float] = {}
    for p in all_powers:
        val = left.get(p, 0.0) - right.get(p, 0.0)
        coeffs[p] = val
    return coeffs


def _fmt_coef(value: float) -> str:
    """
    Formats a coefficient: integers without '.0', floats without trailing zeros.
    """
    if value == int(value):
        return str(int(value))
    return f"{value:.10g}"


def format_reduced(coeffs: dict[int, float]) -> str:
    """
    Formats the coefficient dict into a string like:
      "4 * X^0 + 4 * X^1 - 9.3 * X^2 = 0"

    Zero coefficients are omitted (except when all are zero).
    """
    non_zero = {p: c for p, c in coeffs.items() if c != 0.0}

    if not non_zero:
        return "0 * X^0 = 0"

    powers = sorted(non_zero.keys())

    parts: list[str] = []
    for idx, p in enumerate(powers):
        c = non_zero[p]
        abs_c = abs(c)
        coef_str = _fmt_coef(abs_c)

        if idx == 0:
            # First term: only show sign if negative
            sign_str = "-" if c < 0 else ""
            parts.append(f"{sign_str}{coef_str} * X^{p}")
        else:
            sign_str = "-" if c < 0 else "+"
            parts.append(f"{sign_str} {coef_str} * X^{p}")

    return " ".join(parts) + " = 0"