import sys

input = sys.stdin.readline
INF = int(1e18)


def main():
    N, M = map(int, input().split())
    edges: list[list[int]] = []
    for _ in range(M):
        l, r, s = map(int, input().split())
        edges.append([l - 1, r, -s])
        edges.append([r, l - 1, s])
    for i in range(N):
        edges.append([i, i + 1, -1])

    # Bellman-Ford Algorithm
    dist = [INF] * (N + 1)
    dist[0] = 0
    for _ in range(N):
        updated = False  # For early stopping
        for u, v, w in edges:
            if dist[u] != INF and dist[v] > dist[u] + w:
                dist[v] = dist[u] + w
                updated = True
        if not updated:
            break

    # Check for negative cycles
    for u, v, w in edges:
        if dist[u] != INF and dist[v] > dist[u] + w:
            print(-1)
            return

    print(-dist[N])


if __name__ == "__main__":
    main()
