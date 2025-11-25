/*************************
  Author: Defy logic guy
  10:58:08 - 23/11/2025
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
#define NAME "1746"

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<vector<int>> dp(n, vector<int>(m + 2, 0));

    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            if (a[i] == 0)
                for (int j = 1; j <= m; j++)
                    dp[i][j] = 1;
            else
                dp[i][a[i]] = 1;
        }
        else
        {
            if (a[i] == 0)
            {
                for (int j = 1; j <= m; j++)
                {
                    if (j - 1 >= 1)
                        dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
                    dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
                    if (j + 1 <= m)
                        dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % MOD;
                }
            }
            else
            {
                if (a[i] - 1 >= 1)
                    dp[i][a[i]] = (dp[i][a[i]] + dp[i - 1][a[i] - 1]) % MOD;
                dp[i][a[i]] = (dp[i][a[i]] + dp[i - 1][a[i]]) % MOD;
                if (a[i] + 1 <= m)
                    dp[i][a[i]] = (dp[i][a[i]] + dp[i - 1][a[i] + 1]) % MOD;
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= m; i++)
        ans = (ans + dp[n - 1][i]) % MOD;

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
    cout.tie(nullptr);

    int tt = 1;
    // cin >> tt;

    while (tt--)
        solve();

    return 0;
}
