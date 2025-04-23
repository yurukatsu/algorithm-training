#include <bits/stdc++.h>

#define rng(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) rng(i, 0, n)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

using namespace std;
typedef long long ll;

void solve()
{
    int N;
    ll M;
    cin >> N >> M;

    vector<vector<int>> A(N, vector<int>(N));
    rep(i, N) rep(j, N) cin >> A[i][j];

    if (N == 1)
    {
        cout << (A[0][0] % M) << "\n";
        return;
    }

    int totalMoves = 2 * N - 2;
    int firstMoves = totalMoves / 2;
    int secondMoves = totalMoves - firstMoves;

    vector<ll> pow10(secondMoves + 2);
    pow10[0] = 1 % M;
    rng(i, 1, sz(pow10)) pow10[i] = (pow10[i - 1] * 10) % M;

    vector<vector<ll>> pref(N * N), suf(N * N);

    function<void(int, int, int, ll)> dfsPref = [&](int x, int y, int steps, ll modVal)
    {
        if (steps == firstMoves)
        {
            pref[x * N + y].push_back(modVal);
            return;
        }
        if (x + 1 < N)
            dfsPref(x + 1, y, steps + 1, (modVal * 10 + A[x + 1][y]) % M);
        if (y + 1 < N)
            dfsPref(x, y + 1, steps + 1, (modVal * 10 + A[x][y + 1]) % M);
    };

    function<void(int, int, int, int, ll)> dfsSuf = [&](int x, int y, int steps, int len, ll modVal)
    {
        if (steps == secondMoves)
        {
            suf[x * N + y].push_back(modVal);
            return;
        }
        if (x - 1 >= 0)
            dfsSuf(x - 1, y, steps + 1, len + 1,
                   ((ll)A[x - 1][y] * pow10[len] + modVal) % M);
        if (y - 1 >= 0)
            dfsSuf(x, y - 1, steps + 1, len + 1,
                   ((ll)A[x][y - 1] * pow10[len] + modVal) % M);
    };

    dfsPref(0, 0, 0, A[0][0] % M);
    dfsSuf(N - 1, N - 1, 0, 1, A[N - 1][N - 1] % M);

    ll tenPowSecond = pow10[secondMoves];
    ll best = 0;

    rep(idx, N * N)
    {
        auto &pre = pref[idx];
        auto &sufLst = suf[idx];
        if (pre.empty() || sufLst.empty())
            continue;

        sort(all(sufLst));
        sufLst.erase(unique(all(sufLst)), sufLst.end());

        int cx = idx / N;
        int cy = idx % N;
        int digit = A[cx][cy] % M;

        for (ll p : pre)
        {
            ll base = (((p - digit) % M + M) % M) * tenPowSecond % M;
            ll need = (M - base) % M;

            auto it = lower_bound(all(sufLst), need);
            if (it != sufLst.begin())
            {
                best = max(best, (base + *(it - 1)) % M);
            }
            // wrap-around case
            best = max(best, (base + sufLst.back()) % M);
        }
    }

    cout << best << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}
