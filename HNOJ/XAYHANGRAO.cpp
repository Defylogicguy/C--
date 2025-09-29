/*************************
  Author: Defy logic guy
  18:40:19 - 26/09/2025
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
#define NAME "XAYHANGRAO"

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i].first;
    for (int i = 0; i < n; i++)
        cin >> a[i].second;
    
    sort(rall(a));
    vector<int> f(n), g(n);

    f[0] = a[0].second - a[0].first;
    g[n - 1] = a[n - 1].second;

    for (int i = 1; i < n; i++)
        f[i] = max(f[i - 1], a[i].second - a[i].first);
    for (int i = n - 2; i >= 0; i--)
        g[i] = max(g[i + 1], a[i].second);

    map<int, int> mp;
    int cur = 0;
    for (int i = 0; i < n; i++)
    {
        cur += a[i].first;
        mp[i] = max(cur + f[i], cur - a[i].first + g[i]);
    }
    while (q--)
    {
        int x;
        cin >> x;
        cout << mp[x - 1] << ' ';
    }
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
    // cin >> tt;

    while (tt--)
        solve();

    return 0;
}
