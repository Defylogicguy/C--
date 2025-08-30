/*************************
  Author: Defy logic guy
  19:37:22 - 29/08/2025
*************************/
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define maxall(x) *max_element(all(x))
#define minall(x) *min_element(all(x))
#define heap priority_queue
#define pb push_back
#define MOD 1000000007
#define NAME "LRFUNCTION"

inline int64_t gilbertOrder(int x, int y, int pow, int rotate)
{
    if (pow == 0)
    {
        return 0;
    }
    int hpow = 1 << (pow - 1);
    int seg = (x < hpow) ? ((y < hpow) ? 0 : 3) : ((y < hpow) ? 1 : 2);
    seg = (seg + rotate) & 3;
    const int rotateDelta[4] = {3, 0, 0, 1};
    int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
    int nrot = (rotate + rotateDelta[seg]) & 3;
    int64_t subSquareSize = int64_t(1) << (2 * pow - 2);
    int64_t ans = seg * subSquareSize;
    int64_t add = gilbertOrder(nx, ny, pow - 1, nrot);
    ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
    return ans;
}
int s;
struct Query
{
    int l, r, idx, ord;
    Query(int l = 0, int r = 0, int idx = 0) : l(l), r(r), idx(idx), ord(gilbertOrder(l, r, 21, 0)) {}
    bool operator<(const Query &other) const { return ord < other.ord; }
};

struct Fenwick
{
    int n;
    vector<int> a;
    Fenwick(int n) : n(n) { a.assign(n + 1, 0); }
    void upd(int idx, int x)
    {
        while (idx <= n)
            a[idx] += x, idx += idx & -idx;
    }
    int get(int idx)
    {
        int ans = 0;
        while (idx > 0)
            ans += a[idx], idx -= idx & -idx;
        return ans;
    }
    int sum(int l, int r)
    {
        if (l > r)
            return 0;
        return get(r) - get(l - 1);
    }
};

int n, m;
vector<int> a, par, one, two;
vector<vector<int>> child;
// Cartesian tree
void build()
{
    par.assign(n, -1);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        int lst = -1;
        while (st.size() and a[st.top()] < a[i])
            lst = st.top(), st.pop();
        if (st.size())
            par[i] = st.top();
        if (lst != -1)
            par[lst] = i;
        st.push(i);
    }
    int re = -1;
    for (int i = 0; i < n; i++)
        if (par[i] == -1)
        {
            re = i;
            break;
        }
    child.assign(n, {});
    for (int i = 0; i < n; i++)
        if (par[i] != -1)
            child[par[i]].pb(i);
    one.assign(n, 0), two.assign(n, 0);
    int cur = 0;
    function<void(int)> dfs = [&](int u)
    {
        one[u] = ++cur;
        for (int v : child[u])
            dfs(v);
        two[u] = cur;
    };
    if (re != -1)
        dfs(re);
    else
        for (int i = 0; i < n; i++)
            if (!one[i])
                dfs(i);
}

inline int readInt()
{
    int x = 0, c = getchar(), neg = 0;
    while (c < '0' || c > '9')
    {
        if (c == '-')
            neg = 1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return neg ? -x : x;
}

void solve()
{
    n = readInt(), m = readInt();
    a.resize(n);
    for (int i = 0; i < n; i++)
        a[i] = readInt();
    vector<int> p(n);
    bool asc = false, des = false;
    iota(all(p), 1);
    if (p == a)
        asc = true;
    reverse(all(p));
    if (p == a)
        des = true;
    vector<pair<int, int>> v(m);
    for (int i = 0; i < m; i++)
        v[i].first = readInt();
    for (int i = 0; i < m; i++)
        v[i].second = readInt();
    if (asc or des)
    {
        for (int i = 0; i < m; i++)
        {
            int l = v[i].second - v[i].first + 1;
            cout << l * (l + 1) / 2 << ' ';
        }
        return;
    }
    build();
    vector<Query> q;
    s = n / (int)sqrt(m);
    for (int i = 0; i < m; i++)
        q.emplace_back(v[i].first - 1, v[i].second - 1, i);
    sort(all(q));
    Fenwick bitone(n), bittwo(n);
    auto add = [&](int idx, int &ans)
    {
        int t = one[idx];
        int t1 = two[idx];
        int d = bitone.get(t) - bittwo.get(t - 1) + bitone.sum(t, t1) + 1;
        ans += d;
        bitone.upd(t, 1);
        bittwo.upd(t1, 1);
    };
    auto rm = [&](int idx, int &ans)
    {
        int t = one[idx];
        int t1 = two[idx];
        int d = bitone.get(t) - bittwo.get(t - 1) + bitone.sum(t, t1) - 1;
        ans -= d;
        bitone.upd(t, -1);
        bittwo.upd(t1, -1);
    };
    int cl = 0, cr = -1;
    int cur = 0;
    vector<int> res(m, 0);
    for (int i = 0; i < m; i++)
    {
        int l = q[i].l, r = q[i].r;
        while (cr < r)
            add(++cr, cur);
        while (cr > r)
            rm(cr--, cur);
        while (cl < l)
            rm(cl++, cur);
        while (cl > l)
            add(--cl, cur);
        res[q[i].idx] = cur;
    }
    for (int i = 0; i < m; i++)
        cout << res[i] << ' ';
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
