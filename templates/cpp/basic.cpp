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

// Fenwick Tree (Binary Indexed Tree)
struct Fenwick
{
    int n;
    vector<ll> bit;
    Fenwick(int _n) : n(_n), bit(n + 1, 0) {}
    // Add value v at index i (1-indexed)
    void update(int i, ll v)
    {
        for (; i <= n; i += i & -i)
            bit[i] += v;
    }
    // Query prefix sum up to index i (1-indexed)
    ll query(int i) const
    {
        ll sum = 0;
        for (; i > 0; i -= i & -i)
            sum += bit[i];
        return sum;
    }
    // Range sum [l, r] (1-indexed)
    ll range(int l, int r) const { return query(r) - query(l - 1); }
};

// Segment Tree
template <typename T>
struct SegTree
{
    int n;
    vector<T> seg;
    T identity;
    function<T(const T &, const T &)> combine;

    // n: number of elements, combine: binary operation, identity: identity element
    SegTree(int _n, function<T(const T &, const T &)> _combine, T _identity)
        : n(_n), seg(4 * _n, _identity), identity(_identity), combine(_combine) {}

    // Point update: set element at idx to value v
    void update(int idx, T v) { update(1, 0, n, idx, v); }

    // Range query [l, r)
    T query(int l, int r) { return query(1, 0, n, l, r); }

private:
    void update(int node, int left, int right, int idx, T v)
    {
        if (left + 1 == right)
        {
            seg[node] = v;
            return;
        }
        int mid = (left + right) >> 1;
        if (idx < mid)
            update(2 * node, left, mid, idx, v);
        else
            update(2 * node + 1, mid, right, idx, v);
        seg[node] = combine(seg[2 * node], seg[2 * node + 1]);
    }

    T query(int node, int left, int right, int l, int r)
    {
        if (r <= left || right <= l)
            return identity;
        if (l <= left && right <= r)
            return seg[node];
        int mid = (left + right) >> 1;
        return combine(
            query(2 * node, left, mid, l, r),
            query(2 * node + 1, mid, right, l, r));
    }
};

// Union-Find (Disjoint Set Union)
struct UnionFind
{
    vector<int> parent, rank;
    UnionFind(int n) : parent(n), rank(n, 0) { iota(parent.begin(), parent.end(), 0); }
    // Find root of x with path compression
    int find(int x) { return parent[x] == x ? x : parent[x] = find(parent[x]); }
    // Unite sets containing a and b, return true if merged
    bool unite(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (a == b)
            return false;
        if (rank[a] < rank[b])
            swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b])
            rank[a]++;
        return true;
    }
    // Check if a and b are in the same set
    bool same(int a, int b) { return find(a) == find(b); }
};

// Constants
const int INF = 1e9;
const ll LINF = 4e18;
const ld EPS = 1e-12;
const string YES = "Yes";
const string NO = "No";

// solve() function: write your solution here
void solve()
{
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
