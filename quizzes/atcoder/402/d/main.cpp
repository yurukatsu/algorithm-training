#include <bits/stdc++.h>

#define rng(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) rng(i, 0, n)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

using namespace std;

typedef long long ll;

void solve()
{
    int N, M;
    cin >> N >> M;

    vector<int> cnt(N);
    rep(i, M)
    {
        int a, b;
        cin >> a >> b;
        cnt[(a + b) % N]++;
    }

    ll ans = (ll)M * (M - 1) / 2;
    for (auto e : cnt)
    {
        ans -= (ll)e * (e - 1) / 2;
    }

    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}
