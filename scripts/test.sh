#!/bin/bash

# ANSI color codes
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# Default language
LANG="cpp"

# Help function
show_help() {
    echo -e "${BLUE}Usage: $0 [options] <answer_directory>${NC}"
    echo -e "Example: $0 quizzes/samples/sample01"
    echo -e "\nOptions:"
    echo -e "  -l, --lang LANG   Programming language to use (cpp or python, default: cpp)"
    echo -e "  -h, --help        Show this help message"
}

# Parse command line options
while [[ $# -gt 0 ]]; do
    case $1 in
        -l|--lang)
            LANG=$(echo "$2" | tr '[:upper:]' '[:lower:]')
            if [[ "$LANG" != "cpp" && "$LANG" != "python" ]]; then
                echo -e "${RED}Error: Unsupported language. Supported languages: cpp, python${NC}"
                exit 1
            fi
            shift 2
            ;;
        -h|--help)
            show_help
            exit 0
            ;;
        -*)
            echo -e "${RED}Invalid option: $1${NC}" >&2
            show_help
            exit 1
            ;;
        *)
            break
            ;;
    esac
done

# Check arguments
if [ $# -ne 1 ]; then
    echo -e "${RED}Usage: $0 [options] <answer_directory>${NC}"
    echo -e "Example: $0 quizzes/samples/sample01"
    show_help
    exit 1
fi

ANSWER_DIR=$1

# Determine source file based on language
if [ "$LANG" == "cpp" ]; then
    SOURCE_FILE="main.cpp"
elif [ "$LANG" == "python" ]; then
    SOURCE_FILE="main.py"
else
    echo -e "${RED}Error: Unsupported language. Supported languages: cpp, python${NC}"
    exit 1
fi

# Check if source file exists
if [ ! -f "${ANSWER_DIR}/${SOURCE_FILE}" ]; then
    echo -e "${RED}Error: ${ANSWER_DIR}/${SOURCE_FILE} not found${NC}"
    exit 1
fi

# Check if examples directory exists
if [ ! -d "${ANSWER_DIR}/examples" ]; then
    echo -e "${RED}Error: ${ANSWER_DIR}/examples directory not found${NC}"
    exit 1
fi

# Compile or prepare for execution based on language
if [ "$LANG" == "cpp" ]; then
    echo -e "${BLUE}Compiling C++ code...${NC}"
    g++ -std=c++17 "${ANSWER_DIR}/${SOURCE_FILE}" -o "${ANSWER_DIR}/main"
    if [ $? -ne 0 ]; then
        echo -e "${RED}Compilation error${NC}"
        exit 1
    fi
    echo -e "${GREEN}Compilation successful${NC}"
    EXEC_CMD="${ANSWER_DIR}/main"
elif [ "$LANG" == "python" ]; then
    echo -e "${BLUE}Using Python interpreter...${NC}"
    # Check if Python is available
    if ! command -v python3 &> /dev/null; then
        echo -e "${RED}Error: Python 3 is not installed or not in PATH${NC}"
        exit 1
    fi
    EXEC_CMD="uv run ${ANSWER_DIR}/${SOURCE_FILE}"
else
    echo -e "${RED}Error: Unsupported language. Supported languages: cpp, python${NC}"
    exit 1
fi

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
    ACTUAL_OUTPUT=$(cat "${INPUT_FILE}" | $EXEC_CMD)
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
echo -e "${BLUE}Language: ${LANG}${NC}"
echo -e "${BLUE}Results: ${PASSED}/${TOTAL} test cases passed${NC}"

if [ ${PASSED} -eq ${TOTAL} ]; then
    echo -e "${GREEN}All test cases passed successfully!${NC}"
    exit 0
else
    echo -e "${RED}Some test cases failed.${NC}"
    exit 1
fi
