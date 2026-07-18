/*************************
  Author: Defy logic guy
  21:51:11 - 15/07/2026
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
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define maxall(x) *max_element(all(x))
#define minall(x) *min_element(all(x))
#define heap priority_queue
#define pb push_back
#define MOD 1000000007
#define NAME "TOOLS"

int dp[256][256][17];
void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> a(2 * n + 1);
    a[0] = make_pair(0, 0);
    auto f = [&](const int &i, const int &j) -> int
    { return abs(a[i].first - a[j].first) + abs(a[i].second - a[j].second); };
    for (int i = 1; i <= n; i++)
        cin >> a[i + n].first >> a[i + n].second >> a[i].first >> a[i].second;
    fill(&dp[0][0][0], &dp[0][0][0] + 256 * 256 * 17, INT_MAX);
    dp[0][0][0] = 0;
    int M = (1 << n);
    for (int m1 = 0; m1 < M; m1++)
        for (int m2 = 0; m2 < M; m2++)
        {
            if (__builtin_popcount(m2) > 2)
                continue;
            if (m1 & m2)
                continue;
            for (int i = 0; i <= 2 * n; i++)
            {
                if (dp[m1][m2][i] == INT_MAX)
                    continue;
                if (__builtin_popcount(m2) < 2)
                    for (int j = 0; j < n; j++)
                    {
                        if (m1 & (1 << j))
                            continue;
                        if (m2 & (1 << j))
                            continue;
                        int &t = dp[m1][(m2 | (1 << j))][j + 1];
                        t = min(t, dp[m1][m2][i] + f(i, j + 1));
                    }
                for (int j = 0; j < n; j++)
                {
                    if (!(m2 & (1 << j)))
                        continue;
                    int &t = dp[(m1 | (1 << j))][(m2 ^ (1 << j))][n + 1 + j];
                    t = min(t, dp[m1][m2][i] + f(i, n + 1 + j));
                }
            }
        }
    int ans = INT_MAX;
    for (int i = 0; i <= 2 * n; i++)
    {
        if (dp[M - 1][0][i] == INT_MAX)
            continue;
        ans = min(ans, dp[M - 1][0][i] + f(i, 0));
    }
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

    while (tt--)
        solve();

    return 0;
}
