#!/bin/bash

# ANSI color codes
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# Get script directory for relative paths
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PROJECT_ROOT="$(dirname "$SCRIPT_DIR")"

# Default values
NUM_EXAMPLES=3
LANG="cpp"
DEFAULT_CPP_TEMPLATE="$PROJECT_ROOT/templates/cpp/basic.cpp"
DEFAULT_PYTHON_TEMPLATE="$PROJECT_ROOT/templates/python/basic.py"
TEMPLATE_PATH="$DEFAULT_CPP_TEMPLATE"

# Help function
show_help() {
    echo -e "${BLUE}Usage: $0 [options] <new_directory>${NC}"
    echo -e "Example: $0 quizzes/atcoder/abc123"
    echo -e "\nOptions:"
    echo -e "  -n, --num_examples NUM   Number of example directories to create (default: 3)"
    echo -e "  -t, --template PATH      Path to template file (default: based on language)"
    echo -e "  -l, --lang LANG          Programming language to use (cpp or python, default: cpp)"
    echo -e "  -h, --help               Show this help message"
}

# Parse command line options
while [[ $# -gt 0 ]]; do
    case $1 in
        -n|--num_examples)
            NUM_EXAMPLES=$2
            if ! [[ "$NUM_EXAMPLES" =~ ^[0-9]+$ ]]; then
                echo -e "${RED}Error: Number of examples must be a positive integer${NC}"
                exit 1
            fi
            if [ "$NUM_EXAMPLES" -lt 1 ]; then
                echo -e "${RED}Error: Number of examples must be at least 1${NC}"
                exit 1
            fi
            shift 2
            ;;
        -t|--template)
            # If path is absolute or starts with ./ or ../, use as is
            if [[ "$2" = /* || "$2" = ./* || "$2" = ../* ]]; then
                TEMPLATE_PATH="$2"
            else
                # Otherwise, treat as relative to project root
                TEMPLATE_PATH="$PROJECT_ROOT/$2"
            fi

            # Check if template exists
            if [ ! -f "$TEMPLATE_PATH" ]; then
                echo -e "${RED}Error: Template file $TEMPLATE_PATH not found${NC}"
                exit 1
            fi
            shift 2
            ;;
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

# Set default template based on language if not explicitly provided
if [[ "$TEMPLATE_PATH" == "$DEFAULT_CPP_TEMPLATE" && "$LANG" == "python" ]]; then
    TEMPLATE_PATH="$DEFAULT_PYTHON_TEMPLATE"
fi

# Check if directory argument is provided
if [ $# -ne 1 ]; then
    echo -e "${RED}Error: Missing directory argument${NC}"
    show_help
    exit 1
fi

NEW_DIR=$1

# Check if directory already exists
if [ -d "$NEW_DIR" ]; then
    echo -e "${YELLOW}Warning: Directory $NEW_DIR already exists${NC}"
    read -p "Do you want to overwrite it? (y/n): " -n 1 -r
    echo
    if [[ ! $REPLY =~ ^[Yy]$ ]]; then
        echo -e "${RED}Operation cancelled${NC}"
        exit 1
    fi
fi

# Create directory structure and example files
echo -e "${BLUE}Creating $NUM_EXAMPLES example directories...${NC}"
for i in $(seq -f "%02g" 1 $NUM_EXAMPLES); do
    mkdir -p "$NEW_DIR/examples/$i"
    touch "$NEW_DIR/examples/$i/in.txt"
    touch "$NEW_DIR/examples/$i/out.txt"
done

# Determine output file name based on language
if [ "$LANG" == "cpp" ]; then
    OUTPUT_FILE="main.cpp"
elif [ "$LANG" == "python" ]; then
    OUTPUT_FILE="main.py"
else
    echo -e "${RED}Error: Unsupported language. Supported languages: cpp, python${NC}"
    exit 1
fi

# Create main file from template
if [ ! -f "$TEMPLATE_PATH" ]; then
    echo -e "${RED}Error: Template file $TEMPLATE_PATH not found${NC}"
    exit 1
fi

echo -e "${BLUE}Using template: $TEMPLATE_PATH${NC}"
echo -e "${BLUE}Language: ${LANG}${NC}"
cp "$TEMPLATE_PATH" "$NEW_DIR/$OUTPUT_FILE"

echo -e "${GREEN}Successfully created new project at $NEW_DIR${NC}"
echo -e "${BLUE}Directory structure:${NC}"
find "$NEW_DIR" -type f | sort

echo -e "\n${YELLOW}Next steps:${NC}"
echo -e "1. Edit $NEW_DIR/$OUTPUT_FILE"
echo -e "2. Add test cases to the examples directory"
echo -e "3. Run tests with: alg test $NEW_DIR"

echo -e "\n${GREEN}Created $NUM_EXAMPLES example directories using template: $TEMPLATE_PATH (${LANG})${NC}"
