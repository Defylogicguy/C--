/*************************
  Author: Defy logic guy
  19:13:45 - 10/07/2026
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
#define NAME "AWSN"

const int dx[4] = {0, 0, 1, -1},
          dy[4] = {1, -1, 0, 0};
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int tx = -1, ty = -1, wx = -1, wy = -1;
    vector<pair<int, int>> c;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == 'T')
                tx = i, ty = j;
            else if (a[i][j] == 'W')
                wx = i, wy = j;
            else if (a[i][j] == 'C')
                c.emplace_back(i, j);
        }
    auto bfs = [&](int sx, int sy) -> map<pair<int, int>, int>
    {
        map<pair<int, int>, int> mp;
        vector<vector<int>> dd(n, vector<int>(m, -1));
        queue<pair<int, int>> q;
        q.push({sx, sy});
        dd[sx][sy] = 0;
        while (q.size())
        {
            auto [x, y] = q.front();
            q.pop();
            for (int _ = 0; _ < 4; _++)
            {
                int nx = x + dx[_], ny = y + dy[_];
                if (nx >= 0 and nx < n and ny >= 0 and ny < m and a[nx][ny] != '#' and dd[nx][ny] == -1)
                {
                    dd[nx][ny] = dd[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
        for (auto [x, y] : c)
            mp[{x, y}] = dd[x][y];
        mp[{wx, wy}] = dd[wx][wy];
        return mp;
    };
    int k = c.size();
    if (k == 0)
    {
        auto d = bfs(tx, ty);
        if (d[{wx, wy}] == -1)
            cout << "Mission Failed!\n";
        else
            cout << d[{wx, wy}] << '\n';
        return;
    }
    vector<map<pair<int, int>, int>> d;
    d.pb(bfs(tx, ty));
    for (auto [x, y] : c)
        d.pb(bfs(x, y));
    int M = (1 << k);
    vector<vector<int>> dp(M, vector<int>(k, LLONG_MAX));
    for (int i = 0; i < k; i++)
        if (d[0][c[i]] != -1)
            dp[1 << i][i] = d[0][c[i]];
    for (int mask = 1; mask < (M); mask++)
    {
        for (int i = 0; i < k; i++)
        {
            if (!(mask & (1 << i)))
                continue;
            if (dp[mask][i] == LLONG_MAX)
                continue;
            for (int j = 0; j < k; j++)
            {
                if (mask & (1 << j))
                    continue;
                if (d[i + 1][c[j]] == -1)
                    continue;
                int nmask = mask | (1 << j);
                dp[nmask][j] = min(dp[nmask][j], dp[mask][i] + d[i + 1][c[j]]);
            }
        }
    }
    int ans = LLONG_MAX;
    for (int i = 0; i < k; i++)
        if (dp[M - 1][i] != LLONG_MAX and d[i + 1][{wx, wy}] != -1)
            ans = min(ans, dp[M - 1][i] + d[i + 1][{wx, wy}]);
    if (ans == LLONG_MAX)
        cout << "Mission Failed!\n";
    else
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
    cin >> tt;

    while (tt--)
        solve();

    return 0;
}
