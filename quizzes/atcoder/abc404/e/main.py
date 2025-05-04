import sys

input = sys.stdin.readline


INF = 10**18


def main():
    N = int(input())
    C = [0] + list(map(int, input().split()))
    A = [0] + list(map(int, input().split()))
    L = [i - C[i] for i in range(N)]

    n_operations = 0

    for i in range(N - 1, 0, -1):
        if A[i] == 0:
            continue

        n_operations += 1

        # L_i, L_i -1 , ... , i - 1 のいずれかに豆があるかないかで場合分け
        dest_w_beans = [j for j in range(L[i], i) if A[j] > 0]

        if len(dest_w_beans) > 0:
            # Case 1: 豆がある茶碗が存在する
            # 豆が存在する茶碗の中で最も番号が小さいものを選ぶ
            A[min(dest_w_beans)] += A[i]
            A[i] = 0
        else:
            # Case 2: 豆が存在する茶碗が存在しない
            # L_[L_i], L_[L_i - 1], ... , L_[i - 1] の中で最小の値を与える茶碗を選ぶ
            min_L = INF
            argmin_L = i
            for j in range(L[i], i):
                if L[j] < min_L:
                    min_L = L[j]
                    argmin_L = j
            A[argmin_L] += A[i]
            A[i] = 0

    print(n_operations)


if __name__ == "__main__":
    main()
