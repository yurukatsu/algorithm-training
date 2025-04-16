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
│           ├── main.cpp   # Solution code
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

This will:
1. Compile the `main.cpp` file in the specified directory
2. Run the compiled program with each input file in the `examples` directory
3. Compare the output with the expected output
4. Display the results with color-coding (green for success, red for failure)

#### Creating New Projects

To create a new project with the standard directory structure:

```bash
alg create quizzes/atcoder/abc123
```

This will:
1. Create the directory structure with `examples/01`, `examples/02`, and `examples/03`
2. Create empty input and output files
3. Create a template `main.cpp` file

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

## Workflow Example

1. Create a new project for a problem:
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

## Requirements

- C++ compiler (g++ with C++17 support)
- Bash shell
