import sys
input = sys.stdin.readline

class Trie:
    """
    トライ木
    """
    class Node:
        """
        トライ木のノード
        """
        def __init__(self):
            self.children = {}
            self.value = None

    def __init__(self):
        self.nodes = [self.Node()]

    def add(self,

def main():
    Q = int(input())


if __name__ == "__main__":
    main()
