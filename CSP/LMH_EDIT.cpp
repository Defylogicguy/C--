/*************************
  Author: Defy logic guy
  15:32:45 - 06/12/2025
*************************/
#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) { return os << "(" << p.first << ", " << p.second << ")"; }
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
#define NAME "LMH_EDIT"

void solve()
{
    string s, t;
    cin >> s >> t;
    int ins, del, rep;
    cin >> ins >> del >> rep;
    int m = s.size(), n = t.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    for (int i = 0; i <= n; i++)
        dp[0][i] = i * ins;
    for (int i = 0; i <= m; i++)
        dp[i][0] = i * del;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            if (s[i - 1] == t[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = min({dp[i][j - 1] + ins, dp[i - 1][j] + del, dp[i - 1][j - 1] + rep});
    cout << dp[m][n] << '\n';
    int i = m, j = n;
    while (i > 0 and j > 0)
        if (s[i - 1] == t[j - 1])
            i--, j--;
        else
        {
            if (dp[i][j] == dp[i][j - 1] + ins)
            {
                cout << "INS " << i << ' ' << t[j - 1] << '\n';
                j--;
            }
            else if (dp[i][j] == dp[i - 1][j] + del)
            {
                cout << "DEL " << i - 1 << '\n';
                i--;
            }
            else
            {
                cout << "REP " << i - 1 << ' ' << t[j - 1] << '\n';
                i--, j--;
            }
        }
    for (int k = j - 1; k >= 0; k--)
        cout << "INS 0 " << t[k] << '\n';
    for (int k = i - 1; k >= 0; k--)
        cout << "DEL 0\n";
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
