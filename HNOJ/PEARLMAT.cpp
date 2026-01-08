/*************************
 Author: Defy logic guy
 19:08:10 - 15/08/2025
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
#define NAME "PEARLMAT"

const int maxn = 2e6 + 5;
int binpow(int a, int e)
{
    int r = 1;
    while (e)
    {
        if (e & 1)
            r = (r * a) % MOD;
        a = (a * a) % MOD;
        e >>= 1;
    }
    return r;
}

vector<int> f, invf;

void pre()
{
    f.assign(maxn + 1, 0);
    invf.assign(maxn + 1, 0);
    f[0] = 1;
    for (int i = 1; i <= maxn; i++)
        f[i] = f[i - 1] * i % MOD;
    invf[maxn] = binpow(f[maxn], MOD - 2);
    for (int i = maxn; i >= 1; i--)
        invf[i - 1] = invf[i] * i % MOD;
}

int Cnk(int n, int k)
{
    if (k < 0 or k > n)
        return 0;
    return f[n] * invf[k] % MOD * invf[n - k] % MOD;
}

void solve()
{
    int m, n;
    cin >> m >> n;
    int h1, c1, h2, c2;
    cin >> h1 >> c1 >> h2 >> c2;
    pre();
    int ans = Cnk(m + n - 2, m - 1);
    int cnt = 0;
    if (h1 > 1)
        for (int j = c1; j <= c2; j++)
            cnt = (cnt + Cnk((h1 - 2) + (j - 1), h1 - 2) * Cnk((m - h1) + (n - j), m - h1)) % MOD;
    if (c1 > 1)
        for (int i = h1; i <= h2; i++)
            cnt = (cnt + Cnk((i - 1) + (c1 - 2), i - 1) * Cnk((m - i) + (n - c1), m - i)) % MOD;
    ans = (ans - cnt + MOD) % MOD;
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

    pre();

    while (tt--)
        solve();

    return 0;
}
