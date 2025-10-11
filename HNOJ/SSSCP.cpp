/*************************
  Author: Defy logic guy
  19:47:41 - 03/10/2025
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
#define NAME "SSSCP"

void solve()
{
    int n;
    cin >> n;
    map<int, int> mp;
    auto f = [&mp](int n)
    {
        for (int i = 2; i * i <= n; i++)
        {
            int cnt = 0;
            while (n % i == 0)
                n /= i, cnt++;
            mp[i] += cnt;
        }
        if (n > 1)
            mp[n]++;
    };
    auto binpow = [](int b, int e) -> int
    {
        int ans = 1;
        while (e)
        {
            if (e & 1)
                (ans *= b) %= MOD;
            (b *= b) %= MOD;
            e >>= 1;
        }
        return ans;
    };
    for (int i = 2; i <= n; i++)
        f(i);
    int ans = 1;
    dbg(mp);
    for (auto it : mp)
        (ans *= binpow(it.first, it.second / 2 * 2)) %= MOD;
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
