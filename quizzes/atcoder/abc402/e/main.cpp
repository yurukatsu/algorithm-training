#include <bits/stdc++.h>

#define rng(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) rng(i, 0, n)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

using namespace std;

typedef long long ll;

const double INF = -1.0;

int N, X;
vector<int> S, C; // points and costs
vector<double> P; // probabilities

vector<vector<double>> dp; // mask (2^N states) X money

double dfs(int mask, int money)
{
    double &res = dp[mask][money];
    if (res != INF)
        return res;
    res = 0.0;

    rep(i, N)
    {
        if (mask & (1 << i))
            continue;
        if (money < C[i])
            continue;
        int new_mask = mask | (1 << i);
        int new_money = money - C[i];

        double expectation = P[i] * (S[i] + dfs(new_mask, new_money)) +
                             (1 - P[i]) * dfs(mask, new_money);
        res = max(res, expectation);
    }
    return res;
}

void solve()
{
    cin >> N >> X;
    S.resize(N);
    C.resize(N);
    P.resize(N);

    rep(i, N)
    {
        int p;
        cin >> S[i] >> C[i] >> p;
        P[i] = p / 100.0;
    }

    dp.assign(1 << N, vector<double>(X + 1, INF));

    double ans = dfs(0, X);
    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}
