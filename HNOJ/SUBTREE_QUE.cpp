/*************************
  Author: Defy logic guy
  18:51:55 - 27/02/2026
*************************/
#include <bits/stdc++.h>
using namespace std;
ostream &operator<<(ostream &os, const string &s)
{
    os.write(s.data(), s.size());
    return os;
}
template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) { return os << "(" << p.first << ", " << p.second << ")"; }
template <typename T>
auto operator<<(ostream &os, const T &c) -> typename enable_if<!is_same<T, string>::value, decltype(c.begin(), c.end(), os)>::type
{
    for (auto it = c.begin(); it != c.end(); it++)
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
#define NAME "SUBTREE_QUE"

vector<int> a, vv = {0};
const int maxn = 2e5 + 7;
int tree[4 * maxn];
void init(int idx, int l, int r)
{
    if (l == r)
    {
        tree[idx] = vv[l];
        return;
    }
    int m = l + r >> 1;
    init(2 * idx, l, m);
    init(2 * idx + 1, m + 1, r);
    tree[idx] = tree[2 * idx] + tree[2 * idx + 1];
}

void upd(int idx, int l, int r, int pos, int x)
{
    if (l == r)
    {
        tree[idx] = x;
        return;
    }
    int m = l + r >> 1;
    if (pos <= m)
        upd(2 * idx, l, m, pos, x);
    else
        upd(2 * idx + 1, m + 1, r, pos, x);
    tree[idx] = tree[2 * idx] + tree[2 * idx + 1];
}

int get(int idx, int l, int r, int ql, int qr)
{
    if (l > qr or r < ql)
        return 0;
    if (ql <= l and r <= qr)
        return tree[idx];
    int m = l + r >> 1;
    return get(2 * idx, l, m, ql, qr) + get(2 * idx + 1, m + 1, r, ql, qr);
}

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<vector<int>> adj(n + 1);
    a.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    int t = 0;
    vector<int> tin(n + 1, -1), tout(n + 1, -1);
    function<void(int, int)> dfs = [&](int u, int p)
    {
        tin[u] = ++t;
        vv.pb(a[u]);
        for (int v : adj[u])
            if (v != p)
                dfs(v, u);
        tout[u] = t;
    };
    dfs(1, 0);
    init(1, 1, n);
    while (q--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int i, j;
            cin >> i >> j;
            upd(1, 1, n, tin[i], j);
        }
        else
        {
            int x;
            cin >> x;
            cout << get(1, 1, n, tin[x], tout[x]) << '\n';
        }
    }
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

    int tt = 1;
    // cin >> tt;

    while (tt--)
        solve();

    return 0;
}
