import sys
input = sys.stdin.readline

INF = 10**30


def main():
    N, M = map(int, input().split())
    fees = list(map(int, input().split()))
    animals_in_zoo = [[] for _ in range(N)] # 各動物園にいる動物リスト
    for animal_id in range(M):
        _, *zoo_list = map(int, input().split())
        for z in zoo_list:
            animals_in_zoo[z-1].append(animal_id)

    # 状態を base-3 の整数で表現。桁 j の値が動物 j の「見た回数 (0/1/2)」
    powers = [3**j for j in range(M)]
    full_state = sum(2 * powers[j] for j in range(M))  # 全動物が2回以上見た状態

    # dp: dict { state_id: min_cost }
    dp = {0: 0}

    def add_visits(old_state: int, zoo_animals: list[int], times: int) -> int:
        """
        update state by adding visits to the animals in the zoo
        """
        s = old_state
        for j in zoo_animals:
            c = (s // powers[j]) % 3
            nc = min(2, c + times)
            if nc != c:
                s += (nc - c) * powers[j]
        return s

    for i in range(N):
        new_dp = dp.copy()
        zoo_animals = animals_in_zoo[i]
        fee = fees[i]
        for state, cost in dp.items():
            # 「1回訪れる」
            s1 = add_visits(state, zoo_animals, 1)
            nc1 = cost + fee
            if nc1 < new_dp.get(s1, INF):
                new_dp[s1] = nc1
            # 「2回訪れる」
            s2 = add_visits(state, zoo_animals, 2)
            nc2 = cost + fee * 2
            if nc2 < new_dp.get(s2, INF):
                new_dp[s2] = nc2
        dp = new_dp

    ans = dp.get(full_state)
    print(ans)

if __name__ == "__main__":
    main()
