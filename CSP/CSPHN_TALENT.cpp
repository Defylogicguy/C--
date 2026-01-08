/*************************
  Author: Defy logic guy
  15:42:05 - 24/05/2025
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
#define NAME "CSPHN_TALENT"

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i].first;
    for (int i = 0; i < n; i++)
        cin >> a[i].second;
    sort(all(a));
    vector<int> pf(n + 1, 0), Pf(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        pf[i] = pf[i - 1] + a[i - 1].second;
        Pf[i] = Pf[i - 1] + a[i - 1].second * a[i - 1].first;
    }
    vector<int> idk(n, 0);
    for (int i = 0; i < n; i++)
        idk[i] = a[i].first;
    while (m--)
    {
        int x;
        cin >> x;
        int idx = upper_bound(all(idk), x) - idk.begin();
        cout << x * pf[idx] - Pf[idx] + Pf[n] - Pf[idx] - x * (pf[n] - pf[idx]) << endl;
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
