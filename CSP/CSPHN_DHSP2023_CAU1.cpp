/*************************
  Author: Defy logic guy
  22:15:13 - 20/05/2025
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
#define NAME "CSPHN_DHSP2023_CAU1"

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> pf(n), sf(n);
    pf[0] = 0;
    int lst = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i] > a[i - 1])
            lst = i;
        pf[i] = lst;
    }

    sf[n - 1] = n - 1;
    lst = n - 1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (a[i] > a[i + 1])
            lst = i;
        sf[i] = lst;
    }
    while (m--)
    {
        int l, r;
        cin >> l >> r;
        l--, r--;
        cout << (sf[l] >= pf[r] ? "Yes" : "No") << endl;
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
