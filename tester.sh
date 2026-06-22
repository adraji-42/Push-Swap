#!/bin/bash

# Default values
COUNT=100
LIMIT=0
CHECKER=""
ERROR_FILE="error.txt"

# Counters for statistics
TOTAL_TESTS=0
LIMIT_EXCEEDED_COUNT=0
CHECKER_KO_COUNT=0

# Trap SIGINT (Ctrl+C) and handle cleanup quietly
trap show_stats SIGINT

show_stats() {
    # Suppress error messages during exit
    exec 2>/dev/null
    echo -e "\n\n--- Final Statistics ---"
    echo "Total tests performed: $TOTAL_TESTS"
    if [ "$LIMIT" -gt 0 ]; then
        echo "Limit exceeded: $LIMIT_EXCEEDED_COUNT times"
    fi
    if [ -n "$CHECKER" ]; then
        echo "Checker KO: $CHECKER_KO_COUNT times"
    fi
    echo "------------------------"
    exit 0
}

# Parse flags using getopts
while getopts "n:o:c:" opt; do
  case $opt in
    n) COUNT=$OPTARG ;;
    o) LIMIT=$OPTARG ;;
    c) CHECKER=$OPTARG ;;
    *) echo "Usage: $0 [-n count] [-o ops_limit] [-c checker_path]"; exit 1 ;;
  esac
done

echo "--- Starting Push_Swap Tester ---"
echo "Target Count: $COUNT"
[ "$LIMIT" -ne 0 ] && echo "Ops Limit: $LIMIT" || echo "Ops Limit: No Limit"
[ -n "$CHECKER" ] && echo "Checker: $CHECKER" || echo "Checker: Not used"
echo "Press Ctrl+C to stop and see results."
echo "---------------------------------"

while true
do
    # Generate numbers and hide python errors if interrupted
    ARG=$(python3 -c "import random; print(*(random.sample(range(-2147483648, 2147483648), $COUNT)))" 2>/dev/null)
    
    # Check if ARG is empty (happens when python is interrupted)
    if [ -z "$ARG" ]; then
        continue
    fi

    # Run push_swap and capture output
    INSTRUCTIONS=$(./push_swap $ARG)
    OPS=$(echo "$INSTRUCTIONS" | wc -l)
    
    # Increment total tests counter
    ((TOTAL_TESTS++))

    # 1. Check with external Checker
    if [ -n "$CHECKER" ]; then
        RESULT=$(echo "$INSTRUCTIONS" | ./$CHECKER $ARG)
        if [ "$RESULT" != "OK" ]; then
            echo "❌ Wrong Sorting! Test #$TOTAL_TESTS"
            echo "Numbers: $ARG" >> $ERROR_FILE
            ((CHECKER_KO_COUNT++))
        fi
    fi

    # 2. Check operations limit
    if [ "$LIMIT" -gt 0 ] && [ "$OPS" -gt "$LIMIT" ]; then
        echo "❌ Limit Exceeded: $OPS ops (Test #$TOTAL_TESTS)"
        echo "Numbers: $ARG" >> $ERROR_FILE
        ((LIMIT_EXCEEDED_COUNT++))
    fi

    # Print success status if within limit
    if [ "$LIMIT" -gt 0 ] && [ "$OPS" -le "$LIMIT" ]; then
        STATUS="✅ Test #$TOTAL_TESTS: $OPS ops"
        [ -n "$CHECKER" ] && STATUS="$STATUS | Checker: OK"
        echo "$STATUS"
    elif [ "$LIMIT" -eq 0 ]; then
        echo "✅ Test #$TOTAL_TESTS: $OPS ops"
    fi
done
