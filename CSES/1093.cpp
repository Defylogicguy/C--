/*************************
  Author: Defy logic guy
  11:06:51 - 23/11/2025
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
#define NAME "1093"

void solve()
{
    int n;
    cin >> n;

    int total = n * (n + 1) / 2;
    if (total & 1)
    {
        cout << 0;
        return;
    }

    int x = total / 2;
    vector<vector<int>> dp(n, vector<int>(x + 1));
    dp[0][0] = 1;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= x; j++)
        {
            dp[i][j] = dp[i - 1][j] + (j - i >= 0 ? dp[i - 1][j - i] : 0);
            dp[i][j] %= MOD;
        }
    }

    cout << dp[n - 1][x];
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
