/*************************
  Author: Defy logic guy
  19:57:22 - 06/03/2026
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
#define MOD 1000000000
#define NAME "THT_NENSO"

int binpow(int b, int e)
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
}

int binmul(int a, int b)
{
    if (b == 1)
        return a;
    int ans = 0;
    int t = binmul(a, b / 2);
    if (b & 1)
        ans += a % MOD;
    (ans += t + t) %= MOD;
    return ans;
}

void solve()
{
    int n;
    cin >> n;
    cout << binmul(n + 1, binpow(2, n - 2));
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
