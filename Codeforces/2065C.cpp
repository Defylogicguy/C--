/*************************
  Author: Defy logic guy
  21:31:28 - 09/02/2025
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
#define NAME "2065C"

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    sort(all(b));

    int cur = LLONG_MIN;
    for (int i = 0; i < n; i++)
    {
        int one = (a[i] >= cur ? a[i] : LLONG_MAX);
        auto idk = lower_bound(all(b), a[i] + cur);
        int two = (idk != b.end() ? (*idk - a[i]) : LLONG_MAX);
        if (one == LLONG_MAX and two == LLONG_MAX)
        {
            cout << "NO\n";
            return;
        }
        cur = min(one, two);
    }
    cout << "YES\n";
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
    cin >> tt;

    while (tt--)
        solve();
    return 0;
}
