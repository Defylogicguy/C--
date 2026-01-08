/*************************
  Author: Defy logic guy
  15:27:03 - 02/06/2025
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
#define NAME "CONTEST10_TEAMS"

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(all(a));

    vector<int> two(n + 1);
    two[0] = 1;
    for (int i = 1; i <= n; i++)
        two[i] = (two[i - 1] * 2) % MOD;

    int cur = 0;
    for (int i = 1; i < n; i++)
        cur = (cur + ((a[i] % MOD) * two[n - 1 - i] % MOD)) % MOD;

    int ans = ((2 * (a[0] % MOD)) % MOD) * cur % MOD;
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
