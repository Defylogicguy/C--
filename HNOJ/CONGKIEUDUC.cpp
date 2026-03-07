/*************************
  Author: Defy logic guy
  19:36:37 - 06/03/2026
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
#define NAME "CONGKIEUDUC"

const int K = 2e5 + 7;
int dp[10][K];

void pre()
{
    for (int i = 0; i <= 9; i++)
        dp[i][0] = 1;
    for (int j = 1; j < K; j++)
        for (int i = 0; i <= 9; i++)
            if (i != 9)
                dp[i][j] = dp[i + 1][j - 1];
            else
                (dp[i][j] = dp[1][j - 1] + dp[0][j - 1]) %= MOD;
}

void solve()
{
    string s;
    cin >> s;
    int k;
    cin >> k;
    int ans = 0;
    for (char c : s)
        (ans += dp[c - '0'][k]) %= MOD;
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
    cin >> tt;

    pre();

    while (tt--)
        solve();

    return 0;
}
