/*************************
  Author: Defy logic guy
  22:54:56 - 12/08/2025
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
#define NAME "2131G"

int dfs(int i, int k, const vector<int> &f)
{
    if (!k)
        return 1;
    int ans = i + 1;
    i = min(i - 1, 30ll);
    k--;
    for (int j = 0; j <= i; j++)
        if (k >= (1ll << j))
        {
            k -= (1ll << j);
            ans = (ans * f[j]) % MOD;
        }
        else
        {
            ans = (ans * dfs(j, k, f)) % MOD;
            break;
        }
    return ans % MOD;
}
vector<int> f(31, 0);
void pre()
{
    f[0] = 1;
    for (int i = 1; i < 31; i++)
    {
        f[i] = i + 1;
        for (int j = 0; j < i; j++)
            f[i] = f[i] * f[j] % MOD;
    }
}

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i], a[i]--;
    sort(a.begin(), a.end());
    int ans = 1;
    for (int i = 0; i < n; i++)
        if (a[i] <= 30 and k >= (1ll << a[i]))
        {
            k -= (1ll << a[i]);
            ans = (ans * f[a[i]]) % MOD;
        }
        else
        {
            ans = (ans * dfs(a[i], k, f)) % MOD;
            break;
        }
    cout << ans % MOD << '\n';
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
    cin >> tt;

    pre();

    while (tt--)
        solve();
    return 0;
}
