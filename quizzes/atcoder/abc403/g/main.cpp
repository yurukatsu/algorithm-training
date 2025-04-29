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

// Update minimum/maximum
template <class T>
bool chmin(T &a, const T &b)
{
    if (b < a)
    {
        a = b;
        return true;
    }
    return false;
}

template <class T>
bool chmax(T &a, const T &b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}

// Debug macro (enabled when compiled with -DLOCAL)
#ifdef LOCAL
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << endl;
#else
#define dbg(x) \
    do         \
    {          \
    } while (0)
#endif

// 4-direction vectors
constexpr int dx4[4] = {1, 0, -1, 0};
constexpr int dy4[4] = {0, 1, 0, -1};

// Modular exponentiation
ll modpow(ll a, ll e, ll mod)
{
    ll result = 1;
    while (e)
    {
        if (e & 1)
            result = (__int128)result * a % mod;
        a = (__int128)a * a % mod;
        e >>= 1;
    }
    return result;
}

// GCD and LCM
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

// Constants
const int INF = 1e9;
const ll LINF = 4e18;
const ld EPS = 1e-12;
const ll MOD = 1000000000;

// --- Treap for maintaining sorted multiset and odd-position sums ---
struct Node
{
    ll x;
    ll sum_odd, sum_even; // sums of values at odd/even positions in this subtree
    int cnt;              // subtree size
    ull pr;               // priority
    Node *l, *r;
    Node(ll _x, ull _pr) : x(_x), sum_odd(_x), sum_even(0), cnt(1), pr(_pr), l(nullptr), r(nullptr) {}
};

mt19937_64 rng((unsigned)chrono::steady_clock::now().time_since_epoch().count());
Node *root = nullptr;

inline int get_cnt(Node *t) { return t ? t->cnt : 0; }
inline ll get_sum_odd(Node *t) { return t ? t->sum_odd : 0; }
inline ll get_sum_even(Node *t) { return t ? t->sum_even : 0; }

void upd(Node *t)
{
    if (!t)
        return;
    int ls = get_cnt(t->l);
    int rs = get_cnt(t->r);
    t->cnt = 1 + ls + rs;

    // Compute how right subtree sums shift in parity
    // Positions in right subtree are offset by (ls+1)
    bool shift = ((ls + 1) & 1); // if true, odd<->even swap
    ll rodd = 0, reven = 0;
    if (t->r)
    {
        if (shift)
        {
            rodd = get_sum_even(t->r);
            reven = get_sum_odd(t->r);
        }
        else
        {
            rodd = get_sum_odd(t->r);
            reven = get_sum_even(t->r);
        }
    }

    // Root position is (ls+1)
    bool root_is_odd = ((ls + 1) & 1);
    ll root_odd_val = root_is_odd ? t->x : 0;
    ll root_even_val = root_is_odd ? 0 : t->x;

    // Left subtree sums unchanged
    ll lodd = get_sum_odd(t->l);
    ll leven = get_sum_even(t->l);

    // Aggregate
    t->sum_odd = lodd + root_odd_val + rodd;
    t->sum_even = leven + root_even_val + reven;
}

// Split treap t into l (keys < key) and r (keys >= key)
void split(Node *t, ll key, Node *&l, Node *&r)
{
    if (!t)
    {
        l = r = nullptr;
    }
    else if (t->x < key)
    {
        split(t->r, key, t->r, r);
        l = t;
        upd(l);
    }
    else
    {
        split(t->l, key, l, t->l);
        r = t;
        upd(r);
    }
}

// Merge two treaps a and b (all keys in a < keys in b)
Node *merge(Node *a, Node *b)
{
    if (!a || !b)
        return a ? a : b;
    if (a->pr > b->pr)
    {
        a->r = merge(a->r, b);
        upd(a);
        return a;
    }
    else
    {
        b->l = merge(a, b->l);
        upd(b);
        return b;
    }
}
// --- end of Treap definitions ---

// solve() function: process queries
void solve()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> Q;
    ll z = 0; // previous answer, 0 for the first query

    rep(i, 0, Q)
    {
        ll y;
        cin >> y;
        ll x = ((y + z) % MOD) + 1;

        // Insert x into the treap
        Node *L, *R;
        split(root, x, L, R);
        Node *m = new Node(x, rng());
        root = merge(merge(L, m), R);

        // Compute current sum of odd-positioned elements
        z = get_sum_odd(root);
        cout << z << "\n";
    }
}

int main()
{
    solve();
    return 0;
}
