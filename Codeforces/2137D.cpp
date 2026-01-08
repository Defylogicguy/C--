/*************************
  Author: Defy logic guy
  20:12:37 - 18/09/2025
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
#define NAME "2137D"

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<vector<int>> f(n + 1);
    for (int i = 0; i < n; i++)
        f[a[i]].pb(i);
    vector<int> b(n, 0);
    int cur = 1;
    for (int i = 1; i <= n; i++)
        if (f[i].size() % i != 0)
        {
            cout << -1 << '\n';
            return;
        }
        else
        {
            int c = 0;
            while (c < f[i].size())
            {
                for (int j = 0; j < i; j++)
                    b[f[i][c++]] = cur;
                cur++;
            }
        }
    for (int i = 0; i < n; i++)
        cout << b[i] << " \n"[i == n - 1];
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
