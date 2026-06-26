def gcd(a: int, b: int) -> int:
    """Greatest common divisor via Euclidean algorithm."""
    a, b = abs(a), abs(b)
    while b:
        a, b = b, a % b
    return a


def float_to_fraction(value: float) -> tuple[int, int] | None:
    """
    Tries to represent a float as a 'nice' fraction p/q (q <= 1000).
    Returns (numerator, denominator) in reduced form, or None if not found.
    """
    # Try denominators from 1 to 1000
    for denom in range(1, 1001):
        numer = round(value * denom)
        if abs(numer / denom - value) < 1e-9:
            d = gcd(abs(numer), denom)
            return (numer // d, denom // d)
    return None


def _fmt_fraction(value: float) -> str:
    """
    Formats a real number in decimal form.
    Integers are printed without '.0', others with 6 significant digits.
    """
    if value == int(value):
        return str(int(value))
    return f"{value:.6g}"


def _fmt_complex_part(numer: int, denom: int, is_imag: bool) -> str:
    """
    Formats one part of a complex number.
    is_imag=True  -> "2i/5" or "2i"
    is_imag=False -> "1/5"  or "1"
    """
    if is_imag:
        if denom == 1:
            return f"{numer}i"
        return f"{numer}i/{denom}"
    else:
        if denom == 1:
            return str(numer)
        return f"{numer}/{denom}"


def format_complex(real: float, imag: float) -> str:
    """
    Formats a complex number as "a/b + Ni/D" or "a/b - Ni/D".
    Examples: "-1/5 + 2i/5", "-1/5 - 2i/5"
    """
    r_frac = float_to_fraction(real)
    i_frac = float_to_fraction(abs(imag))

    if r_frac is not None:
        real_str = _fmt_complex_part(r_frac[0], r_frac[1], is_imag=False)
    else:
        real_str = f"{real:.6g}"

    if i_frac is not None:
        imag_str = _fmt_complex_part(i_frac[0], i_frac[1], is_imag=True)
    else:
        imag_str = f"{abs(imag):.6g}i"

    sign = "+" if imag >= 0 else "-"
    return f"{real_str} {sign} {imag_str}"