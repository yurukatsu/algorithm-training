#include <bits/stdc++.h>
using namespace std;

// Type aliases
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

// Loop macros for int
#define rep(i, l, r) for (int i = (l); i < (r); ++i)
#define per(i, r, l) for (int i = (r) - 1; i >= (l); --i)

// Loop macros for long long
#define repll(i, l, r) for (ll i = (l); i < (r); ++i)
#define perll(i, r, l) for (ll i = (r) - 1; i >= (l); --i)

#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

// Constants
const int INF = 1e9;
const ll LINF = 4e18;
const ld EPS = 1e-12;
const string YES = "Yes";
const string NO = "No";

// solve() function: write your solution here
void solve()
{
    int N, M, Q;
    cin >> N >> M >> Q;
    vector<set<int>> can_view(N);
    vector<bool> can_view_all(N, false);
    rep(i, 0, Q)
    {
        int t, x;
        cin >> t >> x;
        --x;
        if (t == 1)
        {
            int y;
            cin >> y;
            --y;
            can_view[x].insert(y);
        }
        else if (t == 2)
        {
            can_view_all[x] = true;
        }
        else
        {
            int y;
            cin >> y;
            --y;
            if (can_view_all[x] || can_view[x].count(y))
            {
                cout << "Yes\n";
            }
            else
            {
                cout << "No\n";
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // Uncomment for multiple test cases:
    // cin >> T;
    while (T--)
        solve();
    return 0;
}
