/*************************
  Author: Defy logic guy
  22:00:22 - 12/05/2025
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
#define NAME "ABC121B"

void solve()
{
    int n, m, c;
    cin >> n >> m >> c;
    vector<int> b(m);
    for (int i = 0; i < m; i++)
        cin >> b[i];
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int cur = 0;
        for (int j = 0; j < m; j++)
        {
            int x;
            cin >> x;
            cur += x * b[j];
        }
        ans += (cur + c > 0);
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
