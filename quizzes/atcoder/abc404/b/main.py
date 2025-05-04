import sys
from typing import Literal

input = sys.stdin.readline

Whiteblack = Literal[".", "#"]

def rotation_90(S: list[list[Whiteblack]]) -> list[list[Whiteblack]]:
    """
    Rotate a 2D list (matrix) 90 degrees clockwise.
    """
    H = len(S)
    W = len(S[0])
    return [[S[H - j - 1][i] for j in range(H)] for i in range(W)]

def count_diff(S: list[list[Whiteblack]], T: list[list[Whiteblack]]) -> int:
    """
    Count the number of positions where S and T differ.
    """
    return sum(
        S[i][j] != T[i][j]
        for i in range(len(S))
        for j in range(len(S[0]))
    )

def main():
    N = int(input())
    S = [list(input().rstrip()) for _ in range(N)]
    T = [list(input().rstrip()) for _ in range(N)]

    ans = 10**9

    for r in range(4):
        ans = min(ans, count_diff(S, T) + r)
        S = rotation_90(S)

    print(ans)

if __name__ == "__main__":
    main()
