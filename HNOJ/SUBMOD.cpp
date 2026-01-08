/*************************
  Author: Defy logic guy
  19:18:36 - 26/09/2025
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
#define NAME "SUBMOD"

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<int> f(n + 1);

    f[1] = 1, f[2] = 2, f[3] = 3;

    for (int i = 4; i <= n; i++)
        f[i] = (f[i - 1] + f[i - 2] + f[i - 3]) % k;

    vector<int> pf(n + 2, 0);
    for (int i = 1; i <= n; i++)
        pf[i] = (pf[i - 1] + f[i]) % k;
    
    map<int, int> mp;
    mp[0] = 0;
    int l, r;
    for (int i = 1; i <= n; i++)
    {
        if (mp.find(pf[i]) != mp.end())
        {
            l = mp[pf[i]] + 1;
            r = i;
            break;
        }
        mp[pf[i]] = i;
    }
    cout << r - l + 1 << '\n';
    for (int i = l; i <= r; i++)
        cout << i << ' ';
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
