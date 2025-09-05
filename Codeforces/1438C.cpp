/*************************
  Author: Defy logic guy
  00:02:07 - 06/09/2025
*************************/
#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) { return os << "(" << p.first << ", " << p.second << ")"; }
template <typename T>
auto operator<<(ostream &os, const T &c) -> decltype(c.begin(), c.end(), os)
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
#define NAME "1438C"

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0, j = 0; i < n; j++, j == m ? (j = 0, i++) : 0)
    {
        cin >> a[i][j];
        (((i + j) % 2 == 0) && (a[i][j] % 2 != 0) && (a[i][j]++)) || (((i + j) % 2 != 0) && (a[i][j] % 2 == 0) && (a[i][j]++));
    }
    for (int i = 0, j = 0; i < n; j++, j == m ? (j = 0, i++) : 0)
        cout << a[i][j] << " \n"[j == m - 1];
    for (int i = 0, j = 0; i < n; j++, j == m ? (j = 0, i++) : 0)
        cerr << a[i][j] << " \n"[j == m - 1];
    cerr << '\n';
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
