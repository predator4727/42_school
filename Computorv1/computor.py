#!/usr/bin/env python3
"""
computor - solver for polynomial equations of degree 2 or lower.

Input format: "a * X^p + b * X^q = c * X^r"
Spaces around '*', '+', '-' are allowed in any amount.
"""

import sys
from parsing import parse_equation
from reduction import reduce_equation
from solver import solve


def main() -> None:
    if len(sys.argv) == 2:
        equation = sys.argv[1]
    elif len(sys.argv) == 1:
        # STDIN mode: keep asking until a non-empty line is entered
        try:
            while True:
                equation = input("Enter equation: ").strip().strip('"').strip("'").strip()
                if equation:
                    break
                print("Error: empty input, please enter an equation.", file=sys.stderr)
        except EOFError:
            print("\nError: unexpected end of input.", file=sys.stderr)
            sys.exit(1)
    else:
        print("Usage: python computor.py \"<equation>\"")
        print('Example: python computor.py "5 * X^0 + 4 * X^1 - 9.3 * X^2 = 1 * X^0"')
        sys.exit(1)

    try:
        left, right = parse_equation(equation)
        coeffs = reduce_equation(left, right)
        solve(coeffs)
    except ValueError as e:
        print(f"Error: {e}", file=sys.stderr)
        sys.exit(1)


if __name__ == "__main__":
    main()
