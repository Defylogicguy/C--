/*************************
  Author: Defy logic guy
  14:59:01 - 22/03/2025
*************************/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define heap priority_queue
#define pb push_back
#define MOD 1000000007
#define endl '\n'
#define NAME "VOLUME"

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int ans = LLONG_MAX;
    for (int i = 0; i < 12; i++)
    {
        int res = 0;
        vector<int> b(a);
        res += i;
        b[1] = (b[1] - i + 12) % 12;
        for (int j = 1; j < n; j++)
        {
            if (b[j] == 0)
                continue;
            int idk = 12 - b[j];
            res += idk;
            b[j + 1] = (b[j + 1] - idk + 12) % 12;
        }
        if (b[n] != 0)
            res += 12 - b[n];
        ans = min(ans, res);
    }
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
