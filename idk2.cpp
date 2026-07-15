/*************************
  Author: Defy logic guy
  21:39:12 - 07/07/2026
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
#define NAME "idk2"

const int dx[4] = {1, -1, 0, 0},
          dy[4] = {0, 0, 1, -1};
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    int mx = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            mx = max(mx, a[i][j]);
        }
    int ans = 0;
    for (int h = 1; h <= mx; h++)
    {
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++)
        {
            if (a[i][0] < h)
                vis[i][0] = true, q.push({i, 0});
            if (a[i][m - 1] < h and !vis[i][m - 1])
                vis[i][m - 1] = true, q.push({i, m - 1});
        }
        for (int j = 0; j < m; j++)
        {
            if (a[0][j] < h and !vis[0][j])
                vis[0][j] = true, q.push({0, j});
            if (a[n - 1][j] < h and !vis[n - 1][j])
                vis[n - 1][j] = true, q.push({n - 1, j});
        }
        while (q.size())
        {
            auto [x, y] = q.front();
            q.pop();
            for (int _ = 0; _ < 4; _++)
            {
                int nx = x + dx[_], ny = y + dy[_];
                if (nx < 0 or nx >= n or ny < 0 or ny >= m or vis[nx][ny] or a[nx][ny] >= h)
                    continue;
                vis[nx][ny] = true;
                q.push({nx, ny});
            }
        }
        for (int i = 1; i < n - 1; i++)
            for (int j = 1; j < m - 1; j++)
                if (a[i][j] < h and !vis[i][j])
                    ans++;
    }
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

    int tt = 1;
    // cin >> tt;

    while (tt--)
        solve();

    return 0;
}
