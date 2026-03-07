/*************************
  Author: Defy logic guy
  14:40:03 - 07/03/2026
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
#define NAME "BLRPATH"

const int LOG = 30;
void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> l(n + 1, -1), r(n + 1, -1);
    for (int i = 1; i <= n; i++)
        cin >> l[i] >> r[i];
    string s;
    for (int i = 0; i < m; i++)
    {
        char c;
        cin >> c;
        s.pb(c);
    }
    vector<int> f(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int cur = i;
        for (int j = 0; j < m; j++)
        {
            if (s[j] == 'L')
                cur = l[cur];
            else
                cur = r[cur];
        }
        f[i] = cur;
    }
    vector<vector<int>> up(LOG, vector<int>(n + 1));
    for (int i = 1; i <= n; i++)
        up[0][i] = f[i];
    for (int i = 1; i < LOG; i++)
        for (int j = 1; j <= n; j++)
            up[i][j] = up[i - 1][up[i - 1][j]];
    int cur = 1;
    for (int i = 0; i < LOG; i++)
        if ((k >> i) & 1ll)
            cur = up[i][cur];
    cout << cur << '\n';
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
