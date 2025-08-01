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
#define NAME "DIVIDEKCOL"

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<int> dp(n + 1), pf(n + 1), cnt(k + 1);
    dp[0] = 1;
    pf[0] = 1;
    int cur = 0, l = 1, idk = 0;

    for (int r = 1; r <= n; r++)
    {
        if (cnt[a[r]]++ == 0)
            cur++;
        if (cur == k)
        {
            while (cnt[a[l]] > 1)
            {
                cnt[a[l]]--;
                l++;
            }
            idk = l;
        }
        dp[r] = idk ? pf[idk - 1] : 0;
        dp[r] %= MOD;
        pf[r] = (pf[r - 1] + dp[r]) % MOD;
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

    while (tt--)
        solve();
    return 0;
}
