#!/bin/bash

# ANSI color codes
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# Check arguments
if [ $# -ne 1 ]; then
    echo -e "${RED}Usage: $0 <answer_directory>${NC}"
    echo -e "Example: $0 quizzes/samples/sample01"
    exit 1
fi

ANSWER_DIR=$1

# Check if main.cpp exists
if [ ! -f "${ANSWER_DIR}/main.cpp" ]; then
    echo -e "${RED}Error: ${ANSWER_DIR}/main.cpp not found${NC}"
    exit 1
fi

# Check if examples directory exists
if [ ! -d "${ANSWER_DIR}/examples" ]; then
    echo -e "${RED}Error: ${ANSWER_DIR}/examples directory not found${NC}"
    exit 1
fi

# Compile
echo -e "${BLUE}Compiling...${NC}"
g++ -std=c++17 "${ANSWER_DIR}/main.cpp" -o "${ANSWER_DIR}/main"
if [ $? -ne 0 ]; then
    echo -e "${RED}Compilation error${NC}"
    exit 1
fi

echo -e "${GREEN}Compilation successful${NC}"

# Run test cases
EXAMPLES_DIR="${ANSWER_DIR}/examples"
PASSED=0
TOTAL=0

# Find test case directories
for TEST_DIR in "${EXAMPLES_DIR}"/*/; do
    TEST_NAME=$(basename "${TEST_DIR}")

    # Check input and output files
    INPUT_FILE="${TEST_DIR}/in.txt"
    EXPECTED_FILE="${TEST_DIR}/out.txt"

    if [ ! -f "${INPUT_FILE}" ] || [ ! -f "${EXPECTED_FILE}" ]; then
        echo -e "${YELLOW}Warning: Input or output file not found for test case ${TEST_NAME}${NC}"
        continue
    fi

    echo -e "${BLUE}Running test case ${TEST_NAME}...${NC}"

    # Run the program and get output
    ACTUAL_OUTPUT=$(cat "${INPUT_FILE}" | "${ANSWER_DIR}/main")
    EXPECTED_OUTPUT=$(cat "${EXPECTED_FILE}")

    # Compare outputs (ignoring trailing whitespace and newlines)
    if [ "$(echo "${ACTUAL_OUTPUT}" | sed -e 's/[ \t]*$//')" = "$(echo "${EXPECTED_OUTPUT}" | sed -e 's/[ \t]*$//')" ]; then
        echo -e "${GREEN}Test case ${TEST_NAME}: PASSED ✓${NC}"
        PASSED=$((PASSED + 1))
    else
        echo -e "${RED}Test case ${TEST_NAME}: FAILED ✗${NC}"
        echo -e "${YELLOW}Expected output:${NC}"
        echo "${EXPECTED_OUTPUT}"
        echo -e "${YELLOW}Actual output:${NC}"
        echo "${ACTUAL_OUTPUT}"
    fi

    TOTAL=$((TOTAL + 1))
done

# Display results
echo ""
echo -e "${BLUE}Results: ${PASSED}/${TOTAL} test cases passed${NC}"

if [ ${PASSED} -eq ${TOTAL} ]; then
    echo -e "${GREEN}All test cases passed successfully!${NC}"
    exit 0
else
    echo -e "${RED}Some test cases failed.${NC}"
    exit 1
fi
