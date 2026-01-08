/*************************
  Author: Defy logic guy
  19:02:34 - 15/08/2025
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
#define NAME "CKN"

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

namespace two
{
    vector<int> p;
    void sieve(int n)
    {
        vector<bool> a(n + 1, true);
        a[0] = a[1] = false;
        for (int i = 2; i * i <= n; i++)
            if (a[i])
                for (int j = i * i; j <= n; j += i)
                    a[j] = false;
        for (int i = 2; i <= n; i++)
            if (a[i])
                p.pb(i);
    }

    int vp(int n, int p)
    {
        int res = 0;
        while (n)
        {
            res += n / p;
            n /= p;
        }
        return res;
    }

    int sol(int mod, int n, int k)
    {
        k = min(k, n - k);
        int ans = 1;
        for (int i : p)
        {
            if (i > n)
                break;
            int cnt = vp(n, i) - vp(k, i) - vp(n - k, i);
            if (cnt)
                ans = (ans * binpow(i, cnt)) % mod;
        }
        return ans;
    }
}

namespace tri
{
    const int maxn = 2e6 + 5;
    int f[maxn], invf[maxn];

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
}

void solve()
{
    int s, t, mod;
    cin >> s >> t >> mod;

    if (s == 2)
        two::sieve(2e6);
    else if (s != 1)
        tri::pre();

    vector<vector<int>> dp;
    if (s == 1)
    {
        dp.assign(2005, vector<int>(2005, 0));
        for (int i = 0; i < 2005; i++)
        {
            dp[i][0] = dp[i][i] = 1;
            for (int j = 1; j < i; j++)
                dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % mod;
        }
    }

    while (t--)
    {
        int n, k;
        cin >> n >> k;
        if (s == 1)
            cout << dp[n][k] << '\n';
        else if (s == 2)
            cout << two::sol(mod, n, k) << '\n';
        else
            cout << tri::Cnk(n, k) << '\n';
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
