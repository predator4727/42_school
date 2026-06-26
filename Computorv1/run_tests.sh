#!/usr/bin/env bash
cd "$(dirname "$0")"

PASS=0
FAIL=0

run() {
    local desc="$1"
    local input="$2"
    local expected="$3"
    local mode="$4"   # "arg" or "stdin"

    if [ "$mode" = "arg" ]; then
        actual=$(python3 computor.py "$input" 2>&1)
    elif [ "$mode" = "stdin" ]; then
        actual=$(echo "$input" | python3 computor.py 2>&1)
    elif [ "$mode" = "eof" ]; then
        actual=$(python3 computor.py < /dev/null 2>&1)
    elif [ "$mode" = "toomany" ]; then
        actual=$(python3 computor.py arg1 arg2 2>&1)
    fi

    if echo "$actual" | grep -qF -- "$expected"; then
        echo "  PASS  $desc"
        PASS=$((PASS + 1))
    else
        echo "  FAIL  $desc"
        echo "        expected to contain: $expected"
        echo "        got: $actual"
        FAIL=$((FAIL + 1))
    fi
}

echo "=== Running tests ==="

# --- from the assignment ---
run "T1: D > 0, two solutions"    "5  *X^0 + 4*  X^1 - 9.3  *X^2 = 1*  X^0"  "strictly positive"  arg
run "T2: degree 1"                 "5*  X^0 + 4  *X^1 = 4*  X^0"                "-0.25"             arg
run "T3: degree 3"                 "8  *X^0 - 6*  X^1 + 0  *X^2 - 5.6*  X^3 = 3  *X^0"  "greater than 2" arg
run "T4: any real number"          "6*  X^0 = 6  *X^0"                           "Any real"         arg
run "T5: no solution"              "10  *X^0 = 15*  X^0"                          "No solution"      arg
run "T6: D < 0, complex"           "1*  X^0 + 2  *X^1 + 5*  X^2 = 0*  X^0"     "-1/5 + 2i/5"     arg
run "T7: bare zero rhs"            "1  *X^0 + 2*  X^1 + 5 * X^2 = 0"            "-1/5 + 2i/5"     arg

# --- extra ---
run "T8: D == 0"                   "1*  X^0 + 2*  X^1 + 1*  X^2 = 0"            "zero"             arg
run "T9: STDIN plain"              "5 * X^0 + 4 * X^1 = 4 * X^0"                "-0.25"            stdin
run "T10: STDIN double-quoted"     '"5 * X^0 + 4 * X^1 = 4 * X^0"'              "-0.25"            stdin
run "T11: STDIN single-quoted"     "'5 * X^0 + 4 * X^1 = 4 * X^0'"              "-0.25"            stdin
run "T12: EOF error"               ""   "unexpected end"   eof
run "T13: too many args"           ""   "Usage"            toomany

echo ""
echo "=== Results: $PASS passed, $FAIL failed ==="
