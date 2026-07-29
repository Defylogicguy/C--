/*************************
  Author: Defy logic guy
  19:21:47 - 15/05/2026
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
#define NAME "MOVE_A"

const int INF = -(1LL << 60);
int up[505][205];
int cur[505][205];
int a[505][505];
void solve()
{
    int m, n, k;
    cin >> m >> n >> k;

    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    for (int j = 0; j <= n; j++)
        for (int l = 0; l < k; l++)
            up[j][l] = INF;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
            for (int l = 0; l < k; l++)
                cur[j][l] = INF;
        for (int j = 1; j <= n; j++)
        {
            if (i == 1 && j == 1)
            {
                cur[j][a[i][j] % k] = a[i][j];
                continue;
            }
            for (int l = 0; l < k; l++)
            {
                int nr = (l + (a[i][j] % k)) % k;

                if (up[j][l] != INF)
                    cur[j][nr] = max(cur[j][nr], up[j][l] + a[i][j]);

                if (cur[j - 1][l] != INF)
                    cur[j][nr] = max(cur[j][nr], cur[j - 1][l] + a[i][j]);
            }
        }
        for (int j = 0; j <= n; j++)
            for (int l = 0; l < k; l++)
                up[j][l] = cur[j][l];
    }
    cout << (up[n][0] == INF ? -1 : up[n][0]);
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
