/*************************
  Author: Defy logic guy
  21:32:01 - 17/09/2025
*************************/
#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) { return os << "(" << p.first << ", " << p.second << ")"; }
template <typename T>
auto operator<<(ostream &os, const T &c) -> decltype(c.begin(), c.end(), os)
{
    for (auto it = c.begin(); it != c.end(); ++it)
        os << (it == c.begin() ? "{" : ", ") << *it;
    return os << "}";
}
#define dbg(x) cerr << #x << " = " << (x) << '\n';
#define int long long
#define float double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define maxall(x) *max_element(all(x))
#define minall(x) *min_element(all(x))
#define heap priority_queue
#define pb push_back
#define MOD 1000000007
#define NAME "SL_SHOOTING"

struct Segtree
{
    int n;
    vector<int> tree, lazy;

    Segtree(int _n) : n(_n)
    {
        tree.assign(n * 4 + 5, 0);
        lazy.assign(n * 4 + 5, 0);
    }

    void build(int node, int l, int r, const vector<int> &sum)
    {
        if (l == r)
        {
            tree[node] = sum[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(node * 2, l, mid, sum);
        build(node * 2 + 1, mid + 1, r, sum);
        tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
    }

    void build(const vector<int> &sum) { build(1, 1, n, sum); }

    void push(int node)
    {
        tree[2 * node] -= lazy[node];
        tree[2 * node + 1] -= lazy[node];
        lazy[2 * node] += lazy[node];
        lazy[2 * node + 1] += lazy[node];
        lazy[node] = 0;
    }

    void update(int node, int l, int r, int u, int v)
    {
        if (l > v || r < u)
            return;
        if (l >= u && r <= v)
        {
            tree[node] -= 1;
            lazy[node] += 1;
            return;
        }
        push(node);
        int mid = (l + r) >> 1;
        update(node * 2, l, mid, u, v);
        update(node * 2 + 1, mid + 1, r, u, v);
        tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
    }

    void update(int l, int r) { update(1, 1, n, l, r); }

    int get(int node, int l, int r, int u, int v)
    {
        if (l > v || r < u)
            return 0;
        if (l >= u && r <= v)
            return tree[node];
        push(node);
        int mid = (l + r) >> 1;
        return max(get(node * 2, l, mid, u, v), get(node * 2 + 1, mid + 1, r, u, v));
    }

    int get(int l, int r) { return get(1, 1, n, l, r); }
};

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;
    auto nen = [&]()
    {
        vector<int> v;
        for (auto &[u, vv] : a)
            v.pb(vv), v.pb(u);
        sort(all(v));
        v.resize(unique(all(v)) - v.begin());
        for (auto &[u, vv] : a)
            tie(u, vv) = make_tuple(upper_bound(all(v), u) - v.begin(), upper_bound(all(v), vv) - v.begin());
    };
    nen();
    vector<int> pos[2 * n + 2], sum(2 * n + 2, 0);
    for (auto [u, v] : a)
    {
        pos[u].pb(v);
        sum[u]++;
        sum[v + 1]--;
    }
    int ans = 0;
    for (int i = 1; i < 2 * n + 2; i++)
    {
        sum[i] += sum[i - 1];
        ans = max(ans, sum[i]);
    }
    Segtree sgt(n * 2);
    sgt.build(sum);
    for (int i = 1; i < 2 * n; ++i)
    {
        for (auto j : pos[i])
            sgt.update(i, j);
        ans = max(ans, sum[i] + sgt.get(i + 1, 2 * n));
    }
    cout << ans;
}

signed main()
{
    if (fopen(NAME ".INP", "r"))
    {
        freopen(NAME ".INP", "r", stdin);
        freopen(NAME ".OUT", "w", stdout);
    }

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int tt = 1;
    // cin >> tt;

    while (tt--)
        solve();

    return 0;
}
