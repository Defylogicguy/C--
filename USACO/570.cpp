/*************************
  Author: Defy logic guy
  20:45:55 - 14/07/2026
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
#define NAME "lightson"

const int dx[4] = {0, 0, -1, 1},
          dy[4] = {1, -1, 0, 0};
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n * n);
    for (int i = 0; i < m; i++)
    {
        int x, y, u, v;
        cin >> x >> y >> u >> v;
        --x, --y, --u, --v;
        adj[x * n + y].pb(u * n + v);
    }
    queue<int> q;
    vector<bool> light(n * n, false), vis(n * n, false);
    light[0] = vis[0] = true;
    q.push(0);
    int ans = 1;
    while (q.size())
    {
        int t = q.front();
        q.pop();
        for (int v : adj[t])
        {
            if (!light[v])
            {
                light[v] = true;
                ans++;
                int x = v / n, y = v % n;
                for (int _ = 0; _ < 4; _++)
                {
                    int nx = x + dx[_], ny = y + dy[_];
                    if (nx < 0 or nx >= n or ny < 0 or ny >= n)
                        continue;
                    if (vis[nx * n + ny])
                    {
                        vis[v] = true;
                        q.push(v);
                        break;
                    }
                }
            }
        }
        int x = t / n, y = t % n;
        for (int _ = 0; _ < 4; _++)
        {
            int nx = x + dx[_], ny = y + dy[_];
            if (nx < 0 or nx >= n or ny < 0 or ny >= n)
                continue;
            int id = nx * n + ny;
            if (light[id] and !vis[id])
            {
                vis[id] = true;
                q.push(id);
            }
        }
    }
    cout << ans;
}

signed main()
{
    freopen(NAME ".in", "r", stdin);
    freopen(NAME ".out", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt = 1;
    // cin >> tt;

    while (tt--)
        solve();

    return 0;
}
