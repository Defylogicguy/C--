/*************************
  Author: Defy logic guy
  14:27:04 - 06/12/2025
*************************/
#include <bits/stdc++.h>
using namespace std;
ostream &operator<<(ostream &os, const string &s)
{
    os.write(s.data(), s.size());
    return os;
}
template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) { return os << "" << p.first << " " << p.second << ""; }
template <typename T>
auto operator<<(ostream &os, const T &c) -> typename enable_if<!is_same<T, string>::value, decltype(c.begin(), c.end(), os)>::type
{
    for (auto it = c.begin(); it != c.end(); it++)
        os << (it == c.begin() ? "" : "\n") << *it;
    return os << "";
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
#define NAME "LMH_BOARD"

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n + 2, vector<int>(m + 2, 0)), dp(n + 2, vector<int>(m + 2, LLONG_MIN)), trace(n + 2, vector<int>(m + 2, -1));

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];

    for (int i = 1; i <= n; i++)
        dp[i][1] = a[i][1];

    for (int j = 2; j <= m; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            int mx = LLONG_MIN;
            int prv = -1;

            if (i > 1 and dp[i - 1][j - 1] > mx)
            {
                mx = dp[i - 1][j - 1];
                prv = i - 1;
            }

            if (dp[i][j - 1] > mx)
            {
                mx = dp[i][j - 1];
                prv = i;
            }

            if (i < n and dp[i + 1][j - 1] > mx)
            {
                mx = dp[i + 1][j - 1];
                prv = i + 1;
            }

            dp[i][j] = mx + a[i][j];
            trace[i][j] = prv;
        }
    }

    int _mx = LLONG_MIN, end = -1;

    for (int i = 1; i <= n; i++)
        if (dp[i][m] > _mx)
        {
            _mx = dp[i][m];
            end = i;
        }

    vector<pair<int, int>> path;
    int cur = end;

    for (int i = m; i >= 1; i--)
    {
        path.pb({cur, i});
        cur = trace[cur][i];
    }

    reverse(all(path));

    cout << _mx << '\n'
         << path;
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
