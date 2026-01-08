/*************************
  Author: Defy logic guy
  15:23:22 - 24/05/2025
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
#define NAME "CONTEST10_DANKIEN"

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), x(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> x[i];
    vector<int> pf(n + 1, 0);
    for (int i = 1; i <= n; i++)
        pf[i] = pf[i - 1] + a[i - 1];
    vector<int> Pf(n + 1, 0);
    for (int i = 1; i <= n; i++)
        Pf[i] = Pf[i - 1] + a[i - 1] * x[i - 1];
    int ans = LLONG_MAX;
    for (int i = 0; i < n; i++)
        ans = min(ans, x[i] * pf[i] - Pf[i] + Pf[n] - Pf[i + 1] - x[i] * (pf[n] - pf[i + 1]));
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
