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
#define MOD 998244353
#define NAME "2136E"

struct DSU
{
    int n;
    vector<int> p;
    DSU(int x) : n(x), p(x + 1)
    {
        for (int i = 0; i <= x; i++)
            p[i] = i;
    }
    int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
    void uni(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (a != b)
            p[b] = a;
    }
};

void solve()
{
    int n, m;
    int v;
    cin >> n >> m >> v;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<vector<int>> g(n + 1);
    vector<pair<int, int>> e;
    for (int i = 0, x, y; i < m; i++)
    {
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
        e.emplace_back(x, y);
    }

    vector<int> d(n + 1), l(n + 1);
    vector<pair<int, int>> s;
    int t = 0;
    vector<vector<int>> cn;
    vector<vector<pair<int, int>>> ce;
    vector<int> cyc;

    function<void(int, int)> dfs = [&](int u, int p)
    {
        d[u] = l[u] = ++t;
        for (int v : g[u])
        {
            if (!d[v])
            {
                s.emplace_back(u, v);
                dfs(v, u);
                l[u] = min(l[u], l[v]);
                if (l[v] >= d[u])
                {
                    vector<int> vs;
                    vector<pair<int, int>> es;
                    unordered_set<int> h;
                    while (s.size())
                    {
                        auto x = s.back();
                        s.pop_back();
                        es.pb(x);
                        if (h.insert(x.first).second)
                            vs.pb(x.first);
                        if (h.insert(x.second).second)
                            vs.pb(x.second);
                        if (x == make_pair(u, v))
                            break;
                    }
                    cn.pb(vs);
                    ce.pb(es);
                    cyc.pb(es.size() >= vs.size());
                }
            }
            else if (v != p and d[v] < d[u])
            {
                s.emplace_back(u, v);
                l[u] = min(l[u], d[v]);
            }
        }
    };

    for (int i = 1; i <= n; i++)
        if (!d[i])
            dfs(i, -1);

    int k = cn.size();
    vector<vector<int>> vc(n + 1);
    for (int i = 0; i < k; i++)
    {
        if (!cyc[i])
            continue;
        for (int x : cn[i])
            vc[x].pb(i);
    }

    vector<int> nb(k, 0);
    for (int i = 0; i < k; i++)
    {
        if (!cyc[i])
            continue;
        auto &vs = cn[i];
        auto &es = ce[i];
        unordered_map<int, int> id;
        for (int j = 0; j < vs.size(); j++)
            id[vs[j]] = j;
        vector<vector<int>> adj(vs.size());
        for (auto &x : es)
        {
            int u = id[x.first], v = id[x.second];
            adj[u].pb(v);
            adj[v].pb(u);
        }
        vector<int> c(vs.size(), -1);
        bool b = 0;
        for (int j = 0; j < vs.size(); j++)
        {
            if (c[j] != -1)
                continue;
            c[j] = 0;
            deque<int> q = {j};
            while (q.size())
            {
                int x = q.front();
                q.pop_front();
                for (int y : adj[x])
                {
                    if (c[y] == -1)
                    {
                        c[y] = c[x] ^ 1;
                        q.pb(y);
                    }
                    else if (c[y] == c[x])
                    {
                        b = 1;
                        break;
                    }
                }
                if (b)
                    break;
            }
            if (b)
                break;
        }
        nb[i] = b;
    }

    int cc = 0;
    vector<int> mp(k, -1);
    for (int i = 0; i < k; i++)
        if (cyc[i])
            mp[i] = cc++;

    DSU dsu(cc + 5);
    for (int i = 1; i <= n; i++)
    {
        auto &lst = vc[i];
        if (lst.empty())
            continue;
        int b = mp[lst[0]];
        for (int j = 1; j < lst.size(); j++)
            dsu.uni(b, mp[lst[j]]);
    }

    vector<int> gn(cc, 0);
    for (int i = 0; i < k; i++)
    {
        if (!cyc[i])
            continue;
        if (nb[i])
        {
            int id = mp[i];
            gn[dsu.find(id)] = 1;
        }
    }

    unordered_map<int, vector<int>> gv;
    for (int i = 1; i <= n; i++)
    {
        if (vc[i].empty())
            continue;
        int gid = dsu.find(mp[vc[i][0]]);
        gv[gid].pb(i);
    }

    int ans = 1;
    bool bad = 0;
    for (auto &[id, vs] : gv)
    {
        if (gn[id])
        {
            for (int x : vs)
                if (a[x] != -1 and a[x] != 0)
                {
                    bad = 1;
                    break;
                }
            if (bad)
                break;
        }
        else
        {
            int pre = -2;
            for (int x : vs)
                if (a[x] != -1)
                    if (pre == -2)
                        pre = a[x];
                    else if (pre != a[x])
                    {
                        bad = 1;
                        break;
                    }
            if (bad)
                break;
            if (pre == -2)
                ans = (ans * (v % MOD)) % MOD;
        }
    }

    if (bad)
    {
        cout << 0 << '\n';
        return;
    }

    for (int i = 1; i <= n; i++)
        if (vc[i].empty() and a[i] == -1)
            ans = (ans * (v % MOD)) % MOD;

    cout << ans << '\n';
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
    cin >> tt;

    while (tt--)
        solve();

    return 0;
}
