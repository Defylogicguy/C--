/*************************
  Author: Defy logic guy
  08:36:00 - 03/05/2026
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
auto operator<<(ostream &os, const T &v) -> typename enable_if<!is_same<T, string>::value, decltype(v.begin(), v.end(), os)>::type
{
    for (auto it = v.begin(); it != v.end(); it++)
        os << (it == v.begin() ? "{" : ", ") << *it;
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
#define NAME "CSPHN_HY_SELFDRV"

const int maxn = 2e6 + 5;
int f[maxn], invf[maxn];

int binpow(int b, int e)
{
    int res = 1;
    while (e)
    {
        if (e & 1)
            res = (res * b) % MOD;
        b = (b * b) % MOD;
        e >>= 1;
    }
    return res;
}

void pre()
{
    f[0] = invf[0] = 1;
    for (int i = 1; i < maxn; ++i)
    {
        f[i] = f[i - 1] * i % MOD;
        invf[i] = binpow(f[i], MOD - 2);
    }
}

int Cnk(int n, int k)
{
    if (k < 0 || k > n)
        return 0;
    return f[n] * invf[k] % MOD * invf[n - k] % MOD;
}

void solve()
{
    int m, n, k;
    cin >> m >> n >> k;
    int ans = Cnk(m + n - 2, m - 1);
    vector<pair<int, int>> a(k);
    for (int i = 0; i < k; i++)
        cin >> a[i].first >> a[i].second;
    a.pb({m, n});
    sort(all(a));
    vector<int> dp(k + 1);
    for (int i = 0; i <= k; i++)
    {
        dp[i] = Cnk(a[i].first + a[i].second - 2, a[i].first - 1);
        for (int j = 0; j < i; j++)
            dp[i] = (dp[i] - dp[j] * Cnk((a[i].first - a[j].first) + (a[i].second - a[j].second), a[i].first - a[j].first) % MOD + MOD) % MOD;
    }
    cout << dp[k] << '\n';
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

    pre();

    while (tt--)
        solve();

    return 0;
}
