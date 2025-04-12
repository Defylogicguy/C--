/*************************
  Author: Defy logic guy
  15:12:46 - 12/04/2025
*************************/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define maxall(x) *max_element(all(x))
#define minall(x) *min_element(all(x))
#define heap priority_queue
#define pb push_back
#define MOD 1000000007
#define endl '\n'
#define NAME "CSPHN_NUMMAX"

void solve()
{
    int n, b;
    cin >> n >> b;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int res = 0;
    int i = 0;
    while (i < n)
    {
        if (a[i] > b)
        {
            i++;
            continue;
        }
        int st = i;
        while (i < n && a[i] <= b)
            i++;
        int en = i;
        int ans = (en - st) * ((en - st) + 1) / 2;
        int cnt = 0;
        int j = st;
        while (j < en)
            if (a[j] < b)
            {
                int one = 0;
                while (j < en && a[j] < b)
                {
                    one++;
                    j++;
                }
                cnt += one * (one + 1) / 2;
            }
            else
                j++;
        res += ans - cnt;
    }
    cout << res;
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
