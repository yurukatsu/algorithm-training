class IsPrime:
    @staticmethod
    def eratosthenes(n: int) -> bool:
        """
        Check if a number is prime using the Sieve of Eratosthenes.

        Args:
            n (int): The number to check.

        Returns:
            bool: True if n is prime, False otherwise.
        """
        assert n >= 1

        if n == 2:
            return True
        if n % 2 == 0:
            return False
        i = 3
        while i * i <= n:
            if n % i == 0:
                return False
            i += 2
        return True

    @staticmethod
    def wheel_factorization(n: int) -> bool:
        """
        Check if a number is prime using wheel factorization.

        Args:
            n (int): The number to check.

        Returns:
            bool: True if n is prime, False otherwise.
        """
        assert n >= 1

        if n in [2, 3, 5]:
            return True
        if any(n % p == 0 for p in [2, 3, 5]):
            return False
        i = 7
        c = 0
        wheel = [4, 2, 4, 2, 4, 6, 2, 6]

        while i * i <= n:
            if n % i == 0:
                return False
            i += wheel[c % 8]
            c += 1
        return True

    @staticmethod
    def _miller_rabin_bases(n: int) -> tuple[int, ...]:
        """
        Get the bases for the Miller-Rabin test based on the value of n.

        Args:
            n (int): The number to check.

        Returns:
            tuple[int]: The bases for the Miller-Rabin test.
        """
        bases: tuple[int, ...]
        if n < 2047:
            bases = (2,)
        elif n < 1373653:
            bases = (2, 3)
        elif n < 9080191:
            bases = (31, 73)
        elif n < 25326001:
            bases = (2, 3, 5)
        elif n < 3215031751:
            bases = (2, 3, 5, 7)
        elif n < 350269456337:
            bases = (
                4230279247111683200,
                14694767155120705706,
                16641139526367750375,
            )
        elif n < 55245642489451:
            bases = (2, 141889084524735, 1199124725622454117, 11096072698276303650)
        elif n < 7999252175582851:
            bases = (
                2,
                4130806001517,
                149795463772692060,
                186635894390467037,
                3967304179347715805,
            )
        elif n < 585226005592931977:
            bases = (
                2,
                123635709730000,
                9233062284813009,
                43835965440333360,
                761179012939631437,
                1263739024124850375,
            )
        elif n < 2**64:
            bases = (2, 325, 9375, 28178, 450775, 9780504, 1795265022)
        elif n < 3317044064679887385961981:
            bases = (2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37)
        else:
            raise OverflowError
        return bases

    @staticmethod
    def miller_rabin(n: int) -> bool:
        """
        Check if a number is prime using the Miller-Rabin primality test.
        Args:
            n (int): The number to check.
        Returns:
            bool: True if n is prime, False otherwise.
        """
        assert n > 1
        if n == 2:
            return True
        elif n % 2 == 0:
            return False
        d = n - 1
        s = 0
        while d & 1 == 0:
            s += 1
            d >>= 1

        mr_bases = IsPrime._miller_rabin_bases(n)
        for a in mr_bases:
            if a == n:
                return False
            a %= n
            x = pow(a, d, n)
            if x == 1 or x == n - 1:
                continue
            for _ in range(s):
                x = pow(x, 2, n)
                if x == n - 1:
                    break
            else:
                return False
        return True


if __name__ == "__main__":
    # Example usage
    for n in [3, 31 ,331, 3331, 33331, 333331, 3333331, 33333331, 333333331]:
        print(f"Is {n} prime? {IsPrime.eratosthenes(n)}")
        print(f"Is {n} prime? {IsPrime.wheel_factorization(n)}")
        print(f"Is {n} prime? {IsPrime.miller_rabin(n)}")
