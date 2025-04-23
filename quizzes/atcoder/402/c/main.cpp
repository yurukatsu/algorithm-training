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

    vector<vector<int>> use(N + 1); // ingredient -> recipe
    vector<int> remain(M);

    rep(i, M)
    {
        int K;
        cin >> K;
        remain[i] = K;
        rep(j, K)
        {
            int a;
            cin >> a;
            use[a].emplace_back(i);
        }
    }

    vector<int> B(N);
    for (int &x : B)
    {
        cin >> x;
    }

    vector<int> ans(N);
    int eatable = 0;

    rep(day, N)
    {
        int x = B[day];
        for (int r : use[x])
        {
            remain[r]--;
            if (remain[r] == 0)
            {
                eatable++;
            }
        }
        cout << eatable << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}
