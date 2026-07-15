/*************************
  Author: Defy logic guy
  20:34:44 - 14/07/2026
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
#define NAME "ccski"

const int dx[4] = {0, 0, 1, -1},
          dy[4] = {1, -1, 0, 0};
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    vector<vector<bool>> w(n, vector<bool>(m, false));
    int wx, wy;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            bool x;
            cin >> x;
            if (x)
            {
                wx = i, wy = j;
                w[i][j] = true;
            }
        }
    auto f = [&](int mid)
    {
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        queue<pair<int, int>> q;
        q.push(make_pair(wx, wy));
        while (q.size())
        {
            auto [x, y] = q.front();
            q.pop();
            for (int _ = 0; _ < 4; _++)
            {
                int nx = x + dx[_], ny = y + dy[_];
                if (nx >= 0 and nx < n and ny >= 0 and ny < m and !vis[nx][ny] and abs(a[nx][ny] - a[x][y]) <= mid)
                {
                    q.push(make_pair(nx, ny));
                    vis[nx][ny] = true;
                }
            }
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (w[i][j] and !vis[i][j])
                    return false;
        return true;
    };
    int l = 0, r = INT_MAX, ans = 0;
    while (l <= r)
    {
        int mid = l + r >> 1;
        if (f(mid))
            ans = mid, r = mid - 1;
        else
            l = mid + 1;
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
