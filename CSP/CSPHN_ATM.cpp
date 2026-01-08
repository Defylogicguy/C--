/*************************
  Author: Defy logic guy
  15:59:06 - 10/05/2025
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
#define NAME "CSPHN_ATM"

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(all(a));

    map<int, bool> mp;
    int M = (1 << n);
    for (int i = 0; i < M; i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
            if (i & (1 << j))
                cnt += a[j];
        mp[cnt] = true;
    }

    int cnt = 0;
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        if (mp[x])
            cnt++;
    }

    cout << cnt << endl;
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
