/*************************
  Author: Defy logic guy
  22:14:52 - 15/08/2025
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
#define NAME "LISYSS"

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
        f[i] = (f[i - 1] * i) % MOD;

    invf[maxn - 1] = power(f[maxn - 1], MOD - 2);
    for (int i = maxn - 2; i >= 1; i--)
        invf[i] = (invf[i + 1] * (i + 1)) % MOD;
}

int Cnk(int n, int k)
{
    if (k < 0 || k > n)
        return 0;
    return f[n] * invf[k] % MOD * invf[n - k] % MOD;
}

void solve()
{
    int n;
    cin >> n;
    int total = 2 * (n - 1);
    int t = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x != -1)
            total -= x;
        else
            t++;
    }

    cout << Cnk(total - 1, t - 1);
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
