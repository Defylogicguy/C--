/*************************
  Author: Defy logic guy
  22:18:39 - 03/12/2025
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
        os << *it << ' ';
    return os;
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
#define NAME "1092"

void solve()
{
    int n;
    cin >> n;
    int sum = (n + 1) * n / 2;
    if (sum & 1)
    {
        cout << "NO\n";
        return;
    }
    int mid = sum / 2;
    vector<int> a;
    int cur = 0;
    for (int i = n; i >= 1; i--)
    {
        if (cur + i > mid)
            break;
        cur += i;
        a.pb(i);
    }
    int left = mid - cur;
    if (left)
        a.pb(left);
    sort(all(a));
    vector<bool> vis(n + 1, false);
    for (int i : a)
        vis[i] = true;
    vector<int> b;
    for (int i = 1; i <= n; i++)
        if (!vis[i])
            b.pb(i);
    cout << "YES\n"
         << a.size() << '\n'
         << a << '\n'
         << b.size() << '\n'
         << b;
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
