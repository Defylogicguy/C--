/*************************
  Author: Defy logic guy
  19:07:08 - 20/03/2026
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
#define NAME "THT2023_HN_SK_C_TRIPLES"

void solve()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> a(m, vector<int>(n)), r(m, vector<int>(3, 0)), c(n, vector<int>(3, 0));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            char ch;
            cin >> ch;
            a[i][j] = ch - '0';
        }
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            r[i][a[i][j]]++, c[j][a[i][j]]++;
    int ans = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            if (!a[i][j])
                continue;
            ans += r[i][3 - a[i][j]] * c[j][3 - a[i][j]];
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
