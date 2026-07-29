/*************************
  Author: Defy logic guy
  18:48:39 - 19/06/2026
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
#define NAME "FOXCHEESE"

void solve()
{
    int n, m;
    cin >> n >> m;
    int nn = n;
    int a[6] = {0};
    while (nn % 2 == 0)
        nn /= 2, a[2]++;
    while (nn % 3 == 0)
        nn /= 3, a[3]++;
    while (nn % 5 == 0)
        nn /= 5, a[5]++;
    int nm = m;
    int b[6] = {0};
    while (nm % 2 == 0)
        nm /= 2, b[2]++;
    while (nm % 3 == 0)
        nm /= 3, b[3]++;
    while (nm % 5 == 0)
        nm /= 5, b[5]++;
    if (nm != nn)
    {
        cout << -1;
        return;
    }
    cout << abs(a[2] - b[2]) + abs(a[3] - b[3]) + abs(a[5] - b[5]);
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
