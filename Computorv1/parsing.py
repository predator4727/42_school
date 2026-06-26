import re

# Term pattern after sign normalization:
# optional sign, coefficient, *, X^, exponent
_TERM_RE = re.compile(
    r'([+-]?)\s*(\d+(?:\.\d+)?)\s*\*\s*[Xx]\^(\d+)'
)


def parse_side(expr: str) -> dict[int, float]:
    """
    Parses one side of the equation into a dict {exponent: coefficient}.

    Strategy: normalize spaces around signs so that '+' and '-' become
    part of the next number, then find all terms with the term pattern.

    If no terms are found, check if the whole side is a bare number
    (e.g. "0" or "42") and treat it as number * X^0.
    """
    coeffs: dict[int, float] = {}
    expr = expr.strip()

    # Remove spaces around '+' and '-' so the sign attaches to the next term
    normalized = re.sub(r'\s*\+\s*', '+', expr)
    normalized = re.sub(r'\s*-\s*', '-', normalized)
    # Strip a leading '+' if present (carries no meaning)
    normalized = normalized.lstrip('+')

    matches = list(_TERM_RE.finditer(normalized))

    if not matches:
        # Try to parse as a bare number: "0", "-5", "3.14"
        bare = re.fullmatch(r'[+-]?\d+(?:\.\d+)?', normalized.strip())
        if bare:
            coeffs[0] = float(bare.group())
            return coeffs
        raise ValueError(f"No recognizable terms in: '{expr}'")

    for m in matches:
        sign_str, coef_str, exp_str = m.group(1), m.group(2), m.group(3)
        sign = -1.0 if sign_str == '-' else 1.0
        coef = sign * float(coef_str)
        exp = int(exp_str)
        coeffs[exp] = coeffs.get(exp, 0.0) + coef

    return coeffs


def parse_equation(equation: str) -> tuple[dict[int, float], dict[int, float]]:
    """
    Splits the equation on '=' and parses each side.
    Returns (left_coeffs, right_coeffs).
    """
    if '=' not in equation:
        raise ValueError("Equation must contain '='")

    parts = equation.split('=')
    if len(parts) != 2:
        raise ValueError("Equation must contain exactly one '='")

    left = parse_side(parts[0])
    right = parse_side(parts[1])
    return left, right