# Algorithm Training

This repository is designed for algorithm training and competitive programming practice. It provides a structured environment for solving programming problems, testing solutions against example cases, and documenting algorithm knowledge.

## Directory Structure

```
algorithm-training/
├── docs/                  # Documentation for algorithms and data structures
├── quizzes/               # Programming problems organized by platform
│   ├── aoj/               # Aizu Online Judge problems
│   ├── atcoder/           # AtCoder problems
│   └── samples/           # Sample problems
│       └── sample01/      # Example problem
│           ├── main.cpp   # C++ solution code
│           ├── main.py    # Python solution code (if using Python)
│           └── examples/  # Test cases
│               ├── 01/    # Test case 1
│               │   ├── in.txt   # Input
│               │   └── out.txt  # Expected output
│               ├── 02/    # Test case 2
│               └── 03/    # Test case 3
└── scripts/               # Utility scripts
    ├── alg                # Main command-line tool
    ├── test.sh            # Test runner script
    └── create.sh          # Project creation script
```

## The `alg` Command

The `alg` command is a utility tool that simplifies common tasks in this environment.

### Setup

To make the `alg` command available system-wide, you can either:

1. Create a symbolic link:
   ```bash
   mkdir -p ~/bin
   ln -s "$(pwd)/scripts/alg" ~/bin/alg
   ```
   (Note: Make sure `~/bin` is in your PATH)

2. Or create an alias:
   ```bash
   echo "alias alg='$(pwd)/scripts/alg'" >> ~/.bashrc
   source ~/.bashrc
   ```

### Available Commands

#### Testing Solutions

To test a solution against example cases:

```bash
alg test quizzes/samples/sample01
```

By default, this will test a C++ solution. To test a Python solution:

```bash
alg test --lang python quizzes/samples/sample01
```

This will:
1. For C++: Compile the `main.cpp` file and run the compiled program
   For Python: Run the `main.py` file with the Python interpreter
2. Run the program with each input file in the `examples` directory
3. Compare the output with the expected output
4. Display the results with color-coding (green for success, red for failure)

#### Creating New Projects

To create a new project with the standard directory structure:

```bash
alg create quizzes/atcoder/abc123
```

By default, this will create a C++ project. To create a Python project:

```bash
alg create --lang python quizzes/atcoder/abc123
```

Additional options:
```bash
alg create --num_examples 5 --template templates/custom.cpp quizzes/atcoder/abc123
```

This will:
1. Create the directory structure with example directories (default: 3)
2. Create empty input and output files
3. Create a template file (`main.cpp` for C++ or `main.py` for Python)

#### Getting Help

To display help information:

```bash
alg help
```

## Documentation

The `docs` directory is intended for storing documentation about algorithms, data structures, and programming techniques that you learn during your competitive programming journey. The directory is organized by algorithm categories to make it easy to find and reference specific techniques.

### Documentation Structure

```
docs/
├── data-structures/              # Data Structures
│   ├── arrays-and-lists/         # Arrays and Lists
│   ├── stacks-and-queues/        # Stacks and Queues
│   ├── trees/                    # Trees
│   ├── heaps/                    # Heaps
│   ├── hash-tables/              # Hash Tables
│   └── union-find/               # Union-Find (Disjoint Set)
│
├── graph-algorithms/             # Graph Algorithms
│   ├── traversal/                # Graph Traversal (DFS, BFS)
│   ├── shortest-paths/           # Shortest Paths
│   ├── minimum-spanning-tree/    # Minimum Spanning Tree
│   ├── topological-sort/         # Topological Sort
│   └── network-flow/             # Network Flow
│
├── dynamic-programming/          # Dynamic Programming (DP)
│   ├── knapsack/                 # Knapsack Problem
│   ├── lcs/                      # Longest Common Subsequence
│   ├── edit-distance/            # Edit Distance
│   ├── range-dp/                 # Range DP
│   ├── bit-dp/                   # Bit DP
│   └── tree-dp/                  # Tree DP
│
├── search-algorithms/            # Search Algorithms
├── sorting-algorithms/           # Sorting Algorithms
├── string-algorithms/            # String Algorithms
├── mathematical-algorithms/      # Mathematical Algorithms
├── computational-geometry/       # Computational Geometry
└── techniques/                   # Techniques and Paradigms
    ├── greedy/                   # Greedy Algorithms
    ├── divide-and-conquer/       # Divide and Conquer
    ├── sliding-window/           # Sliding Window
    └── two-pointers/             # Two Pointers
```

## Workflow Examples

### C++ Workflow

1. Create a new C++ project for a problem:
   ```bash
   alg create quizzes/atcoder/abc123
   ```

2. Add the problem's example test cases to the `examples` directory

3. Implement your solution in `main.cpp`

4. Test your solution:
   ```bash
   alg test quizzes/atcoder/abc123
   ```

5. Iterate on your solution until all tests pass

6. Document any new algorithms or techniques you learned in the `docs` directory

### Python Workflow

1. Create a new Python project for a problem:
   ```bash
   alg create --lang python quizzes/atcoder/abc123
   ```

2. Add the problem's example test cases to the `examples` directory

3. Implement your solution in `main.py`

4. Test your solution:
   ```bash
   alg test --lang python quizzes/atcoder/abc123
   ```

5. Iterate on your solution until all tests pass

6. Document any new algorithms or techniques you learned in the `docs` directory

## Requirements

- C++ compiler (g++ with C++17 support) for C++ solutions
- Python 3.6+ for Python solutions
- [uv](https://github.com/astral-sh/uv) - Fast Python package installer and resolver
- Bash shell

### Installing uv

To install uv, follow these instructions:

```bash
# Install with curl
curl -sSf https://astral.sh/uv/install.sh | sh

# Or install with pip
pip install uv
```

For more installation options, visit the [uv installation guide](https://github.com/astral-sh/uv#installation).
