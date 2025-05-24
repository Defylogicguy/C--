/*************************
  Author: Defy logic guy
  14:45:25 - 24/05/2025
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
#define endl '\n'
#define NAME "CONTEST10_TIENPHAT"

void solve()
{
    int n;
    cin >> n;

    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;

    sort(all(a));

    vector<int> pf(n + 1, 0), ans(n + 1, LLONG_MAX);
    for (int i = 1; i <= n; i++)
        pf[i] = pf[i - 1] + a[i - 1].first;

    ans[0] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            ans[i] = min(ans[i], ans[j - 1] + pf[i] - pf[j - 1] - a[j - 1].first * (i - j + 1) + a[j - 1].second);

    cout << ans[n];
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
