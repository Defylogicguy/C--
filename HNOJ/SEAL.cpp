/*************************
  Author: Defy logic guy
  20:13:14 - 10/10/2025
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
#define NAME "SEAL"

void solve()
{
    int n, d;
    cin >> n >> d;
    vector<vector<int>> dp(n + 1, vector<int>(12, LLONG_MAX)), la(n + 1, vector<int>(12));
    dp[0][11] = 1;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        a[i] = x;
        if ((x % 2 == 0 and d & 1) or (x % 5 == 0 and d % 5 != 0))
        {
            for (int j = 0; j < 12; j++)
                dp[i][j] = dp[i - 1][j], la[i][j] = -j;
            continue;
        }
        for (int j = 0; j < 12; j++)
            if (dp[i][j] / x >= dp[i - 1][j])
                dp[i][j] = dp[i - 1][j] * x, la[i][j] = -j;
        for (int j = 0; j < 12; j++)
            if (dp[i][j * x % 10] > dp[i - 1][j])
                dp[i][j * x % 10] = dp[i - 1][j], la[i][j * x % 10] = j;
    }
    if (dp[n][d] == LLONG_MAX)
    {
        cout << -1;
        return;
    }
    vector<int> ans;
    for (int i = n; i >= 1; i--)
        if (la[i][d] >= 0)
            ans.pb(i), d = la[i][d];
    cout << ans.size() << '\n';
    for (int i = ans.size() - 1; i >= 0; i--)
        cout << a[ans[i]] << ' ';
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
