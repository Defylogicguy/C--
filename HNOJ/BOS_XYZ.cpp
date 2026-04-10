/*************************
  Author: Defy logic guy
  18:50:51 - 03/04/2026
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
#define NAME "BOS_XYZ"

vector<__int128> p(19);
void pre()
{
    p[0] = 1;
    for (int i = 1; i < 19; i++)
        p[i] = p[i - 1] * 10;
}

void solve()
{
    int l, r, t, k;
    cin >> l >> r >> t >> k;
    if ((k / t) >= 18)
    {
        cout << 0 << '\n';
        return;
    }

    int a = r / (int)p[k / t] - r / (int)p[k / t + 1];
    int b = (l - 1) / (int)p[k / t] - (l - 1) / (int)p[k / t + 1];

    cout << a - b << '\n';
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
    pre();

    while (tt--)
        solve();

    return 0;
}
