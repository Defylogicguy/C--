/*************************
  Author: Defy logic guy
  19:41:57 - 05/09/2025
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
#define NAME "SOYEUTHICH"

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; cin >> a[i++])
        ;
    vector<int> d(n - 1), v(n - 1);
    int base = 0;
    for (int i = 0; i < n - 1; i++)
    {
        v[i] = a[i + 1];
        d[i] = (a[i + 1] - a[i] + m) % m;
        base += d[i];
    }
    vector<int> b(m + 3, 0), ad(m + 3, 0), bd(m + 3, 0);
    for (int i = 0; i < n - 1; i++)
    {
        if (!d[i])
            continue;
        int l = v[i] - d[i] + 1;
        if (l >= 1)
        {
            b[l] += d[i] - 1;
            b[v[i] + 1] -= d[i] - 1;
            ad[l]--;
            ad[v[i] + 1]++;
            bd[l] += v[i];
            bd[v[i] + 1] -= v[i];
        }
        else
        {
            b[1] += d[i] - 1;
            b[v[i] + 1] -= d[i] - 1;
            ad[1]--;
            ad[v[i] + 1]++;
            bd[1] += v[i];
            bd[v[i] + 1] -= v[i];
            b[l + m] += d[i] - 1;
            b[m + 1] -= d[i] - 1;
            ad[l + m]--;
            ad[m + 1]++;
            bd[l + m] += v[i] + m;
            bd[m + 1] -= v[i] + m;
        }
    }
    int ans = LLONG_MAX;
    int cur = 0, cura = 0, curb = 0;
    for (int i = 1; i <= m; i++)
    {
        cur += b[i];
        cura += ad[i];
        curb += bd[i];
        ans = min(ans, base - cur + cura * i + curb);
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
