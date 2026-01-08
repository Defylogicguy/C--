/*************************
  Author: Defy logic guy
  23:57:51 - 03/08/2025
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
#define NAME "DPCOUNT_LSTONCE"

const int maxn = 1e6 + 5;
int f[maxn], invf[maxn];

int power(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

int cnk(int n, int k)
{
    if (k < 0 or k > n)
        return 0;
    return (((f[n] * invf[k]) % MOD) * invf[n - k]) % MOD;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    f[0] = 1;
    for (int i = 1; i < maxn; i++)
        f[i] = (f[i - 1] * i) % MOD;
    invf[maxn - 1] = power(f[maxn - 1], MOD - 2);
    for (int i = maxn - 2; i >= 0; i--)
        invf[i] = (invf[i + 1] * (i + 1)) % MOD;
    int ans = 0;
    for (int i = 0; i <= k; i++)
    {
        int idk = (i & 1 ? -1 : 1);
        ans = (ans + idk * ((cnk(k, i) * power(k - i, n)) % MOD)) % MOD;
        if (ans < 0)
            ans += MOD;
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
