/*************************
  Author: Defy logic guy
  19:56:55 - 07/07/2026
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
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define maxall(x) *max_element(all(x))
#define minall(x) *min_element(all(x))
#define heap priority_queue
#define pb push_back
#define MOD 1000000007
#define NAME "1682"

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1), radj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        radj[v].pb(u);
    }
    vector<bool> a(n + 1, false);
    queue<int> q;
    q.push(1);
    while (q.size())
    {
        int t = q.front();
        q.pop();
        a[t] = true;
        for (int v : adj[t])
            if (!a[v])
                q.push(v);
    }
    vector<bool> b(n + 1, false);
    q.push(1);
    while (q.size())
    {
        int t = q.front();
        q.pop();
        b[t] = true;
        for (int v : radj[t])
            if (!b[v])
                q.push(v);
    }
    bool flag = true;
    for (int i = 2; i <= n; i++)
        flag &= (a[i] & b[i]);
    if (flag)
        cout << "YES";
    else
        for (int i = 2; i <= n; i++)
            if (!a[i])
            {
                cout << "NO\n1" << ' ' << i;
                break;
            }
            else if (!b[i])
            {
                cout << "NO\n"
                     << i << ' ' << 1;
                break;
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
