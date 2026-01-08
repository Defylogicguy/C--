/*************************
  Author: Defy logic guy
  14:32:03 - 22/11/2025
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
#define NAME "BARSPLIT"

void solve()
{
    int n, k, p;
    cin >> n >> k >> p;
    string s;
    cin >> s;
    s = " " + s;

    vector<int> dp(n + 1), pf(n + 1);
    dp[0] = pf[0] = 1;

    int cl = 0;
    int cnt = 0;

    for (int i = 1; i <= n; ++i)
    {
        if (s[i] == 'X')
            cnt++;
        while (cnt > p)
        {
            cl++;
            if (s[cl] == 'X')
                cnt--;
        }
        int l = cl;
        if (i - k > l)
            l = i - k;
        if (l < 0)
            l = 0;
            
        if (l <= i - 1)
        {
            int t = (l - 1 >= 0) ? pf[l - 1] : 0;
            dp[i] = (pf[i - 1] - t + MOD) % MOD;
        }
        else
            dp[i] = 0;
        (pf[i] = pf[i - 1] + dp[i]) %= MOD;
    }

    cout << dp[n] << '\n';
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
    cin >> tt;

    while (tt--)
        solve();

    return 0;
}
