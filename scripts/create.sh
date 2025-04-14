#!/bin/bash

# ANSI color codes
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# Check arguments
if [ $# -ne 1 ]; then
    echo -e "${RED}Usage: $0 <new_directory>${NC}"
    echo -e "Example: $0 quizzes/atcoder/abc123"
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

# Create directory structure
mkdir -p "$NEW_DIR/examples/01"
mkdir -p "$NEW_DIR/examples/02"
mkdir -p "$NEW_DIR/examples/03"

# Create empty input and output files
touch "$NEW_DIR/examples/01/in.txt"
touch "$NEW_DIR/examples/01/out.txt"
touch "$NEW_DIR/examples/02/in.txt"
touch "$NEW_DIR/examples/02/out.txt"
touch "$NEW_DIR/examples/03/in.txt"
touch "$NEW_DIR/examples/03/out.txt"

# Create main.cpp template
cat > "$NEW_DIR/main.cpp" << 'EOF'
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    // Your code here

    return 0;
}
EOF

echo -e "${GREEN}Successfully created new project at $NEW_DIR${NC}"
echo -e "${BLUE}Directory structure:${NC}"
find "$NEW_DIR" -type f | sort

echo -e "\n${YELLOW}Next steps:${NC}"
echo -e "1. Edit $NEW_DIR/main.cpp"
echo -e "2. Add test cases to the examples directory"
echo -e "3. Run tests with: alg test $NEW_DIR"
