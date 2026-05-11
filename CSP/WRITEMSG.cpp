/*************************
  Author: Defy logic guy
  14:23:52 - 09/05/2026
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
#define NAME "WRITEMSG"

void solve()
{
    int n, m;
    cin >> n >> m;
    string c, s;
    cin >> c >> s;
    vector<int> dp(n, INT_MAX);
    for (int i = 0; i < n; i++)
        if (c[i] == s[0])
            dp[i] = 0;
    for (int i = 1; i < m; i++)
    {
        vector<int> pf(n), sf(n);
        pf[0] = dp[0];
        for (int j = 1; j < n; j++)
            pf[j] = min(pf[j - 1], dp[j] - j);
        sf[n - 1] = dp[n - 1] - (n - 1) + n;
        for (int j = n - 2; j >= 0; j--)
            sf[j] = min(sf[j + 1], dp[j] - j + n);
        vector<int> ndp(n, INT_MAX);
        for (int j = 0; j < n; j++)
        {
            if (c[j] != s[i])
                continue;
            int t = pf[j];
            if (j + 1 < n)
                t = min(t, sf[j + 1]);
            ndp[j] = j + t;
        }
        dp.swap(ndp);
    }
    int ans = INT_MAX;
    for (int v : dp)
        ans = min(ans, v);
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
