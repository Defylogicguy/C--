/*************************
  Author: Defy logic guy
  10:52:21 - 22/02/2026
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
#define NAME "XORPATH"

const int maxn = 2e5 + 7;
struct Trie
{
    struct node
    {
        int child[2];
        node() : child{-1, -1} {}
    };

    vector<node> a;
    Trie() { a.pb(node()); }
    void ins(int x)
    {
        int pos = 0;
        for (int i = 30; i >= 0; i--)
        {
            int b = (x >> i) & 1ll;
            if (a[pos].child[b] == -1)
                a[pos].child[b] = a.size(), a.pb(node());
            pos = a[pos].child[b];
        }
    }
    int get(int x)
    {
        int pos = 0;
        if (a[pos].child[0] == -1 && a[pos].child[1] == -1)
            return -1;
        int ans = 0;
        for (int i = 30; i >= 0; i--)
        {
            int b = (x >> i) & 1LL;
            int p = a[pos].child[b ^ 1];
            if (p != -1)
                ans |= (1LL << i), pos = p;
            else if (a[pos].child[b] != -1)
                pos = a[pos].child[b];
            else
                return -1;
        }
        return ans;
    }
} tree[4 * maxn];

void upd(int idx, int l, int r, int pos, int val)
{
    tree[idx].ins(val);
    if (l == r)
        return;
    int m = l + r >> 1;
    if (pos <= m)
        upd(2 * idx, l, m, pos, val);
    else
        upd(2 * idx + 1, m + 1, r, pos, val);
}

int get(int idx, int l, int r, int ql, int qr, int x)
{
    if (qr < l or r < ql)
        return -1;
    if (ql <= l and r <= qr)
        return tree[idx].get(x);
    int m = l + r >> 1;
    return max(get(2 * idx, l, m, ql, qr, x), get(2 * idx + 1, m + 1, r, ql, qr, x));
}

void solve()
{
    int q;
    cin >> q;
    vector<vector<pair<int, int>>> adj(maxn);
    vector<pair<int, pair<int, int>>> qry;
    int cnt = 1;
    while (q--)
    {
        string t;
        cin >> t;
        int x, y;
        cin >> x >> y;
        if (t[0] == 'A')
        {
            cnt++;
            adj[x].emplace_back(cnt, y);
            adj[cnt].emplace_back(x, y);
            qry.pb({1, {cnt, 0}});
        }
        else
            qry.pb({2, {x, y}});
    }
    vector<int> pf(maxn + 1, 0);
    vector<int> vec, tin(maxn + 1), tout(maxn + 1);
    int t = 0;
    function<void(int, int)> f = [&](int u, int p)
    {
        tin[u] = ++t;
        vec.pb(u);
        for (auto [v, w] : adj[u])
            if (v != p)
            {
                pf[v] = pf[u] ^ w;
                f(v, u);
            }
        tout[u] = t;
    };
    f(1, 0);
    upd(1, 1, cnt, tin[1], pf[1]);
    for (auto it : qry)
        if (it.first == 1)
            upd(1, 1, cnt, tin[it.second.first], pf[it.second.first]);
        else
            cout << max(0ll, get(1, 1, cnt, tin[it.second.second], tout[it.second.second], pf[it.second.first])) << '\n';
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
