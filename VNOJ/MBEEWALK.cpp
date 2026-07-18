/*************************
  Author: Defy logic guy
  22:02:34 - 12/11/2025
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
#define NAME "MBEEWALK"

int dp[40][40][40];
void solve()
{

    int dx[6] = {1, 0, -1, 0, 1, -1};
    int dy[6] = {0, 1, 0, -1, 1, -1};
    dp[20][20][0] = 1;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= 38; j++)
            for (int k = 1; k <= 38; k++)
            {
                dp[j][k][i] = 0;
                for (int l = 0; l < 6; l++)
                    dp[j][k][i] += dp[j + dx[l]][k + dy[l]][i - 1];
            }
    cout << dp[20][20][n] << '\n';
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
