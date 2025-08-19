/*************************
  Author: Defy logic guy
  22:56:04 - 15/08/2025
*************************/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define maxall(x) *max_element(all(x))
#define minall(x) *min_element(all(x))
#define heap priority_queue
#define pb push_back
#define MOD 1000000007
#define NAME "ATCODERDPY"

const int maxn = 1e6 + 5;
vector<int> f(maxn), invf(maxn);

int power(int b, int e)
{
    int res = 1;
    b %= MOD;
    while (e)
    {
        if (e & 1)
            (res *= b) %= MOD;
        (b *= b) %= MOD;
        e >>= 1;
    }
    return res;
}

void pre()
{
    f[0] = invf[0] = 1;
    for (int i = 1; i < maxn; i++)
    {
        f[i] = f[i - 1] * i % MOD;
        invf[i] = power(f[i], MOD - 2);
    }
}

int Cnk(int n, int k)
{
    if (k < 0 or k > n)
        return 0;
    return ((f[n] * invf[k]) % MOD * invf[n - k]) % MOD;
}

void solve()
{
    int h, w, n;
    cin >> h >> w >> n;
    vector<int> dp(n + 2, 0);
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i].first >> v[i].second, v[i].first--, v[i].second--;
    v.pb({h - 1, w - 1});
    sort(all(v));
    for (int i = 0; i <= n; i++)
    {
        auto [x, y] = v[i];
        dp[i] = Cnk(x + y, x);
        for (int j = 0; j < i; j++)
        {
            auto [u, l] = v[j];
            if (y < l)
                continue;
            dp[i] = (dp[i] - dp[j] * Cnk(x + y - u - l, x - u) % MOD + MOD) % MOD;
        }
    }
    cout << dp[n];
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

    pre();

    while (tt--)
        solve();

    return 0;
}
