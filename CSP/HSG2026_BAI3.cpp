/*************************
  Author: Defy logic guy
  15:29:40 - 11/04/2026
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
#define NAME "HSG2026_BAI3"

const int N = 505;
int dp[N][N], ndp[N][N];
void solve()
{
    int n, l, r;
    cin >> n >> l >> r;
    dp[1][1] = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= min(i, l); j++)
            for (int k = 1; k <= min(i, r); k++)
            {
                (ndp[j][k] += (i - 2) * dp[j][k]) %= MOD;
                if (j >= 2)
                    (ndp[j][k] += dp[j - 1][k]) %= MOD;
                if (k >= 2)
                    (ndp[j][k] += dp[j][k - 1]) %= MOD;
            }
        swap(dp, ndp);
        memset(ndp, 0, sizeof(ndp));
    }
    cout << dp[l][r];
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
