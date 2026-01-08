/*************************
  Author: Defy logic guy
  14:14:14 - 02/06/2025
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
#define NAME "MEDIUON_SQRNUM2"

void solve()
{
    int n;
    cin >> n;

    vector<int> spf(n + 1);
    for (int i = 2; i <= n; i++)
        if (spf[i] == 0)
            for (int j = i; j <= n; j += i)
                if (spf[j] == 0)
                    spf[j] = i;

    vector<int> num(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        int x = i, idk = 1;
        while (x > 1)
        {
            int p = spf[x];
            int cnt = 0;
            while (x % p == 0)
            {
                x /= p;
                cnt++;
            }
            if (cnt % 2 == 1)
                idk *= p;
        }
        num[idk]++;
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans += num[i] * num[i];

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
