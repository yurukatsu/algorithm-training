import sys
from collections import defaultdict

input = sys.stdin.readline

class UnionFind:
    __slots__ = ["parent", "rank", "size"]

    def __init__(self, n: int):
        """
        Initialize the Union-Find structure with n elements.

        Args:
            n (int): The number of elements in the Union-Find structure.
        """
        self.parent = list(range(n))
        self.rank = [0] * n
        self.size = [1] * n

    def find_root(self, x: int) -> int:
        """
        Find the root of the set containing x.

        Args:
            x (int): The element to find.

        Returns:
            int: The root of the set containing x.
        """
        if self.parent[x] != x:
            self.parent[x] = self.find_root(self.parent[x])
        return self.parent[x]

    def unite(self, x: int, y: int) -> None:
        """
        Union the sets containing x and y.

        Args:
            x (int): The first element.
            y (int): The second element.
        """
        root_x = self.find_root(x)
        root_y = self.find_root(y)

        if root_x == root_y:
            return

        if self.rank[root_x] > self.rank[root_y]:
            self.parent[root_y] = root_x
            self.size[root_x] += self.size[root_y]
        elif self.rank[root_x] < self.rank[root_y]:
            self.parent[root_x] = root_y
            self.size[root_y] += self.size[root_x]
        else:
            self.parent[root_y] = root_x
            self.rank[root_x] += 1
            self.size[root_x] += self.size[root_y]

    def is_same(self, x: int, y: int) -> bool:
        """
        Check if x and y are in the same set.

        Args:
            x (int): The first element.
            y (int): The second element.

        Returns:
            bool: True if x and y are in the same set, False otherwise.
        """
        return self.find_root(x) == self.find_root(y)

    def get_size(self, x: int) -> int:
        """
        Get the size of the set containing x.

        Args:
            x (int): The element to find the size of its set.

        Returns:
            int: The size of the set containing x.
        """
        return self.size[self.find_root(x)]

    def get_all_groups(self) -> list[set[int]]:
        """
        Get all groups in the Union-Find structure.

        Returns:
            list[set[int]]: A list of sets, each containing the elements of a group.
        """
        groups = defaultdict(set)
        for i in range(len(self.parent)):
            groups[self.find_root(i)].add(i)
        return list(groups.values())

def main():
    N, M = map(int, input().split())

    if N != M :
        print("No")
        return

    # Graph
    G = {i: [] for i in range(N)}
    uf = UnionFind(N)
    for _ in range(M):
        u, v = map(int, input().split())
        u -= 1
        v -= 1
        G[u].append(v)
        G[v].append(u)
        uf.unite(u, v)

    for n in G:
        if len(G[n]) != 2:
            print("No")
            return

    if len(uf.get_all_groups()) != 1:
        print("No")
    else:
        print("Yes")

if __name__ == "__main__":
    main()
