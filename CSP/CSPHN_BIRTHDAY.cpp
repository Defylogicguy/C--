/*************************
  Author: Defy logic guy
  15:52:19 - 09/08/2025
*************************/
#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long
#define float double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define maxall(x) *max_element(all(x))
#define minall(x) *min_element(all(x))
#define heap priority_queue
#define pb push_back
#define MOD 1000000007
#define NAME "CSPHN_BIRTHDAY"

const int maxn = 1e7 + 7;
int v[maxn];
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        for (int j = 0; a[i] * j < maxn; j++)
            v[a[i] * j] = a[i];
    int cur = 0;
    vector<int> dp(maxn, LLONG_MAX);
    dp[0] = 0;
    for (int i = 1; i < maxn; i++)
    {
        while (cur + 1 <= i and cur + v[cur] <= i)
            cur++;
        if (cur != i)
            dp[i] = dp[cur] + 1;
    }
    while (m--)
    {
        int x;
        cin >> x;
        if (dp[x] >= LLONG_MAX)
            cout << "oo\n";
        else
            cout << dp[x] << '\n';
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
