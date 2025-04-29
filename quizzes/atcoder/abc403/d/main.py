import sys
input = sys.stdin.readline

M = 10**6 # A[i] の上限

def main():
    N, D = map(int, input().split())
    A = list(map(int, input().split()))
    cnt = [0] * (M + 1) # 値 v の出現回数

    for a in A:
        cnt[a] += 1

    if D == 0:
        print(
            sum(max(x - 1, 0) for x in cnt)
        )
        exit()

if __name__ == "__main__":
    main()
