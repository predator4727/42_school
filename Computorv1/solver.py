from reduction import format_reduced
from sqrt import polynomial_degree
from sqrt import sqrt
from number_format import _fmt_fraction
from number_format import format_complex

def solve(coeffs: dict[int, float]) -> None:
    """
    Solves the equation by degree and prints the result.
    """
    reduced_str = format_reduced(coeffs)
    print(f"Reduced form: {reduced_str}")

    # All coefficients are zero: any real number is a solution (degree 0, not printed)
    all_zero = all(c == 0.0 for c in coeffs.values())
    if all_zero:
        print("Any real number is a solution.")
        return

    degree = polynomial_degree(coeffs)

    if degree == 0:
        # Only a non-zero constant term: no solution (degree 0, not printed)
        print("No solution.")
        return

    print(f"Polynomial degree: {degree}")

    if degree > 2:
        print("The polynomial degree is strictly greater than 2, I can't solve.")
        return

    a = coeffs.get(2, 0.0)  # coefficient of X^2
    b = coeffs.get(1, 0.0)  # coefficient of X^1
    c = coeffs.get(0, 0.0)  # coefficient of X^0

    if degree == 1:
        # b*x + c = 0  =>  x = -c / b
        x = -c / b
        print(f"The solution is:\n{_fmt_fraction(x)}")
        return

    # degree == 2
    discriminant = b * b - 4 * a * c

    if discriminant > 0:
        sqrt_d = sqrt(discriminant)
        x1 = (-b + sqrt_d) / (2 * a)
        x2 = (-b - sqrt_d) / (2 * a)
        print("Discriminant is strictly positive, the two solutions are:")
        print(_fmt_fraction(x1))
        print(_fmt_fraction(x2))

    elif discriminant == 0:
        x = -b / (2 * a)
        print("Discriminant is zero, the solution is:")
        print(_fmt_fraction(x))

    else:
        # discriminant < 0: complex roots
        real_part = -b / (2 * a)
        imag_part = sqrt(-discriminant) / (2 * a)
        print("Discriminant is strictly negative, the two complex solutions are:")
        print(format_complex(real_part, imag_part))
        print(format_complex(real_part, -imag_part))