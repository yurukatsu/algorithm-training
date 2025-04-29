import sys
input = sys.stdin.readline

YES = "Yes"
NO = "No"

def main():
    N, M, Q = map(int, input().split())
    can_view_all = [False for _ in range(N)]
    can_view = [set() for _ in range(N)]

    for _ in range(Q):
        t, *q = map(int, input().split())
        x = q[0] - 1

        if t == 1:
            y = q[1] - 1
            can_view[x].add(y)
        if t == 2:
            can_view_all[x] = True
        if t == 3:
            y = q[1] - 1
            if can_view_all[x]:
                print(YES)
            else:
                print(YES if y in can_view[x] else NO)

if __name__ == "__main__":
    main()
