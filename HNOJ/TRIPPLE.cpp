/*************************
  Author: Defy logic guy
  15:27:21 - 29/08/2025
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
#define NAME "TRIPPLE"

int modpow(int b, int e)
{
    int res = 1;
    while (e)
    {
        if (e & 1)
            (res *= b) %= MOD;
        (b *= b) %= MOD;
        e >>= 1;
    }
    return res;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n + 1);
    v[0] = 0;
    for (int i = 1; i <= n; i++)
        v[i] = (v[i - 1] * 10 + 1) % k;
    vector<int> w(n + 1);
    for (int i = 1; i <= n; i++)
        w[i] = ((i % k) * v[n - i + 1]) % k;
vector<int> dp(k);
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        vector<int> ndp(k);
        for (int j = 0; j < k; j++)
        {
            if (!dp[j])
                continue;
            for (int l = (i == 1 ? 1 : 0); l <= 7; ++l)
                (ndp[((j + l * w[i]) % k)] += dp[j]) %= MOD;
        }
        dp.swap(ndp);
    }

    int cnt = 0;
    for (int i = 0; i < k; i++)
    {
        if (!dp[i])
            continue;
        for (int j = 0; j < k; j++)
        {
            if (!dp[j])
                continue;
            int l = (k - (i + j) % k) % k;
            int add = dp[i] * dp[j] % MOD * dp[l] % MOD;
            (cnt += add) %= MOD;
        }
    }

    // 3 so
    int tri = 0;
    for (int i = 0; i < k; i++)
        if ((3 * i) % k == 0)
            (tri += dp[i]) %= MOD;
    // 2 so
    int two = 0;
    for (int i = 0; i < k; i++)
    {
        if (!dp[i])
            continue;
        for (int j = 0; j < k; j++)
        {
            if (!dp[j])
                continue;
            if ((2 * i + j) % k == 0)
            {
                int t = (dp[i] * ((dp[j] - (i == j ? 1 : 0) + MOD) % MOD)) % MOD;
                (two += t) %= MOD;
            }
        }
    }
    two = (3 * two) % MOD;
    // 1 so
    int one = (((cnt - two) % MOD - tri) % MOD + MOD) % MOD;

    cout << (one * modpow(6, MOD - 2)) % MOD << '\n';
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
