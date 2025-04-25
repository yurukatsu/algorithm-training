#include <bits/stdc++.h>

#define rng(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) rng(i, 0, n)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

using namespace std;

typedef long long ll;

void solve()
{
    ll n, m;
    cin >> n >> m;
    ll cur = 1, sum = 0;
    for (int i = 0; i <= m; i++)
    {
        sum += cur;
        if (sum > 1'000'000'000)
        {
            cout << "inf\n";
            return;
        }
        cur *= n;
    }
    cout << sum << '\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}
