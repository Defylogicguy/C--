/*************************
  Author: Defy logic guy
  14:51:44 - 27/09/2025
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
#define NAME "DNT"

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> qry(q);
    int mx = 0;
    for (int i = 0; i < q; i++)
    {
        cin >> qry[i];
        mx = max(mx, qry[i]);
    }

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 1e18));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++)
    {
        vector<vector<int>> ndp(n + 1, vector<int>(n + 1, 1e18));
        for (int j = 0; j <= n; j++)
            for (int k = 0; k <= i; k++)
            {
                if (dp[j][k] == 1e18)
                    continue;
                int c = (a[i] == 1);
                if (j + c <= n)
                    ndp[j + c][k] = min(ndp[j + c][k], dp[j][k] + k);
                c = (a[i] == 0);
                if (j + c <= n)
                    ndp[j + c][k + 1] = min(ndp[j + c][k + 1], dp[j][k]);
            }
        swap(dp, ndp);
    }

    for (int k : qry)
    {
        int ans = 1e18;
        int lim = min(k, n);
        for (int i = 0; i <= lim; i++)
            for (int j = 0; j <= n; j++)
                ans = min(ans, dp[i][j]);
        cout << ans << '\n';
    }
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
