/*************************
  Author: Defy logic guy
  18:56:54 - 24/10/2025
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
#define NAME "BIENDOI"

int n, m, q;
vector<vector<int>> tree;
vector<int> ot, oa, ob, ans;
vector<vector<int>> grid;
vector<int> r;
int cnt;

void f(int idx)
{
    int t = ot[idx];
    if (t == 1)
    {
        int x = oa[idx], y = ob[idx];
        if (grid[x][y] == 0)
        {
            grid[x][y] = 1;
            r[x]++, cnt++;
        }
    }
    else if (t == 2)
    {
        int x = oa[idx], y = ob[idx];
        if (grid[x][y] == 1)
        {
            grid[x][y] = 0;
            r[x]--, cnt--;
        }
    }
    else if (t == 3)
    {
        int x = oa[idx];
        for (int j = 1; j <= m; j++)
            grid[x][j] = 1 - grid[x][j];
        cnt -= r[x];
        r[x] = m - r[x];
        cnt += r[x];
    }
}

void ff(int idx)
{
    int t = ot[idx];
    if (t == 1)
    {
        int x = oa[idx], y = ob[idx];
        if (grid[x][y] == 1)
        {
            grid[x][y] = 0;
            r[x] -= 1;
            cnt -= 1;
        }
    }
    else if (t == 2)
    {
        int x = oa[idx], y = ob[idx];
        if (grid[x][y] == 0)
        {
            grid[x][y] = 1;
            r[x]++, cnt++;
        }
    }
    else if (t == 3)
    {
        int x = oa[idx];
        for (int j = 1; j <= m; j++)
            grid[x][j] = 1 - grid[x][j];
        cnt -= r[x];
        r[x] = m - r[x];
        cnt += r[x];
    }
}

void dfs(int v)
{
    if (v != 0)
    {
        f(v);
        ans[v] = cnt;
    }
    for (int u : tree[v])
        dfs(u);
    if (v != 0)
        ff(v);
}

void solve()
{
    cin >> n >> m >> q;
    tree.assign(q + 1, {}), ot.assign(q + 1, 0), oa.assign(q + 1, 0), ob.assign(q + 1, 0), ans.assign(q + 1, 0);
    for (int i = 1; i <= q; i++)
    {
        int t;
        cin >> t;
        ot[i] = t;
        int par;
        if (t == 1 || t == 2)
        {
            int x, y;
            cin >> x >> y;
            oa[i] = x;
            ob[i] = y;
            par = i - 1;
        }
        else if (t == 3)
        {
            int x;
            cin >> x;
            oa[i] = x;
            par = i - 1;
        }
        else if (t == 4)
        {
            int x;
            cin >> x;
            par = x;
        }
        tree[par].pb(i);
    }
    grid.assign(n + 1, vector<int>(m + 1, 0));
    r.assign(n + 1, 0);
    cnt = 0;
    dfs(0);
    for (int i = 1; i <= q; i++)
        cout << ans[i] << '\n';
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
