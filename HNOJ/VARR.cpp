/*************************
  Author: Defy logic guy
  19:53:04 - 31/10/2025
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
#define NAME "VARR"

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), pf(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pf[i] = pf[i - 1] + a[i];
    }
    vector<int> res(22, 0);
    for (int i = 0; i <= 20; i++)
    {
        int x = (1 << i);
        vector<int> v(n + 1);
        for (int j = 1; j <= n; j++)
            v[j] = pf[j] % x;
        map<int, int> mp;
        mp[0] = 1;
        for (int j = 1; j <= n; j++)
        {
            res[i] += mp[v[j]];
            mp[v[j]]++;
        }
    }
    int ans = 0;
    for (int i = 0; i <= 20; i++)
    {
        ans += (1 << i) * (res[i] - res[i + 1]);
        ans %= MOD;
    }
    cout << ans;
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
