#include <bits/stdc++.h>

#define rng(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) rng(i, 0, n)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

using namespace std;

typedef long long ll;

void solve()
{
    ll n;
    cin >> n;

    cout << (ll)sqrtl(n / 2) + (ll)sqrtl(n / 4) << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}
