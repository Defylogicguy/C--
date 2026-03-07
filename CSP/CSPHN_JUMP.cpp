/*************************
  Author: Defy logic guy
  14:49:00 - 28/02/2026
*************************/
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
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
#define NAME "CSPHN_JUMP"

const int maxn = 4005;
int a[maxn], b[maxn], dp[maxn][maxn], row[maxn][maxn], col[maxn][maxn];
void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
        cin >> b[i];
    dp[1][1] = 1;
    for (int i = 1, cur = 0; i <= n; i++, cur = 0)
        for (int j = 1; j <= m; j++)
        {
            cur += row[i][j];
            if (cur >= MOD)
                cur -= MOD;
            (col[i][j] += col[i - 1][j]);
            if (col[i][j] >= MOD)
                col[i][j] -= MOD;
            (dp[i][j] += cur + col[i][j]);
            if (dp[i][j] >= MOD)
                dp[i][j] -= MOD;
            if (!dp[i][j])
                continue;
            int c = 1 + (a[i] + b[j]) % k;
            int l = j + 1, r = min(m, j + c);
            if (l <= r)
            {
                (row[i][l] += dp[i][j]), (row[i][r + 1] += -dp[i][j] + MOD);
                if (row[i][l] >= MOD)
                    row[i][l] -= MOD;
                if (row[i][r + 1] >= MOD)
                    row[i][r + 1] -= MOD;
            }
            l = i + 1, r = min(n, i + c);
            if (l <= r)
            {
                (col[l][j] += dp[i][j]), (col[r + 1][j] += -dp[i][j] + MOD);
                if (col[l][j] >= MOD)
                    col[l][j] -= MOD;
                if (col[r + 1][j] >= MOD)
                    col[r + 1][j] -= MOD;
            }
        }
    cout << dp[n][m];
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
