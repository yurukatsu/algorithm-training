import sys

input = sys.stdin.readline


def main():
    N, T, M, K = map(int, input().split())
    min_NM = min(N, M)
    # dp の設定
    # dp[t][k]: t ターン目が終わった時に，あたりのボタンが k 回押された状態からゲームを続け，
    # 最適な行動を続けたときに勝利（T ターン目に K 回以上あたりのボタンを押すことができる）確率
    dp = [[0] * (K + 1) for _ in range(T + 1)]
    dp[-1][-1] = 1

    # dp の更新
    for t in range(T - 1, -1, -1):
        for k in range(K + 1):
            dp2 = [[0] * (M + 1) for _ in range(min_NM + 1)]

            for n in range(min_NM):
                for s in range(M + 1):
                    for c in range(1, M - s + 1):
                        dp2[n + 1][s + c] = max(
                            dp2[n + 1][s + c], dp2[n][s] + dp[t + 1][min(K, k + c)]
                        )
            dp1_NM = 0
            for n in range(1, min_NM + 1):
                dp1_NM = max(dp1_NM, dp2[n][M] + (N - n) * dp[t + 1][k])

            dp[t][k] = dp1_NM / N

    print(dp[0][0])


if __name__ == "__main__":
    main()
