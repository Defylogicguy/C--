/*************************
  Author: Defy logic guy
  14:29:52 - 27/12/2025
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
#define NAME "LMH_BISHOP"

const int N = 205;
int dp[2][N][N];
void solve()
{
    int n, k;
    cin >> n >> k;
    memset(dp, 0, sizeof(dp));
    auto f = [&](int color) -> int
    {
        int t = 0;
        vector<int> c(n + 1, 0);
        for (int i = color + 1; i <= n; i += 2)
        {
            c[++t] = i;
            if (i != n)
                c[++t] = i;
        }
        for (int i = 0; i <= t; i++)
            dp[color][i][0] = 1;
        for (int i = 1; i <= t; i++)
            for (int j = 1; j <= c[i]; j++)
                dp[color][i][j] = (dp[color][i - 1][j] + (dp[color][i - 1][j - 1] * (c[i] - j + 1)) % MOD) % MOD;
        return t;
    };
    int zer = f(0), one = f(1);
    int ans = 0;
    for (int i = 0; i <= k; i++)
        (ans += (dp[0][zer][i] * dp[1][one][k - i]) % MOD) %= MOD;
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
