/*************************
  Author: Defy logic guy
  15:48:07 - 21/03/2026
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
#define NAME "PUSHUP"

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    vector<vector<int>> dp1(n, vector<int>(m, LLONG_MAX));
    dp1[0][0] = a[0][0];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (i > 0)
                dp1[i][j] = min(dp1[i][j], dp1[i - 1][j] + a[i][j]);
            if (j > 0)
                dp1[i][j] = min(dp1[i][j], dp1[i][j - 1] + a[i][j]);
        }
    vector<vector<int>> dp2(n, vector<int>(m, LLONG_MAX));
    dp2[n - 1][m - 1] = a[n - 1][m - 1];
    for (int i = n - 1; i >= 0; i--)
        for (int j = m - 1; j >= 0; j--)
        {
            if (j < m - 1)
                dp2[i][j] = min(dp2[i][j], dp2[i][j + 1] + a[i][j]);
            if (i < n - 1)
                dp2[i][j] = min(dp2[i][j], dp2[i + 1][j] + a[i][j]);
        }
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (dp1[i][j] + dp2[i][j] - a[i][j] == dp1[n - 1][m - 1])
                vis[i][j] = true;
    int ans = 0;
    for (int d = 2; d < n + m - 1; d++)
    {
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            int j = d - i;
            if (j < 0 or j >= m)
                continue;
            if (vis[i][j] and !(i == 0 and j == 0) and !(i == n - 1 and j == m - 1))
                v.pb(dp1[i][j] + dp2[i][j] - a[i][j]);
        }

        if (v.size() == 1)
            ans = max(ans, v[0]);
    }
    cout << ans;
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
