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
├── data-structures/              # データ構造
│   ├── arrays-and-lists/         # 配列・リスト
│   ├── stacks-and-queues/        # スタック・キュー
│   ├── trees/                    # 木構造
│   ├── heaps/                    # ヒープ
│   ├── hash-tables/              # ハッシュテーブル
│   └── union-find/               # Union-Find（素集合データ構造）
│
├── graph-algorithms/             # グラフアルゴリズム
│   ├── traversal/                # グラフ探索（DFS、BFS）
│   ├── shortest-paths/           # 最短経路
│   ├── minimum-spanning-tree/    # 最小全域木
│   ├── topological-sort/         # トポロジカルソート
│   └── network-flow/             # ネットワークフロー
│
├── dynamic-programming/          # 動的計画法（DP）
│   ├── knapsack/                 # ナップサック問題
│   ├── lcs/                      # 最長共通部分列
│   ├── edit-distance/            # 編集距離
│   ├── range-dp/                 # 区間DP
│   ├── bit-dp/                   # ビットDP
│   └── tree-dp/                  # 木DP
│
├── search-algorithms/            # 探索アルゴリズム
├── sorting-algorithms/           # ソートアルゴリズム
├── string-algorithms/            # 文字列アルゴリズム
├── mathematical-algorithms/      # 数学的アルゴリズム
├── computational-geometry/       # 計算幾何学
└── techniques/                   # テクニック・パラダイム
    ├── greedy/                   # 貪欲法
    ├── divide-and-conquer/       # 分割統治法
    ├── sliding-window/           # スライディングウィンドウ
    └── two-pointers/             # 二ポインタ
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
