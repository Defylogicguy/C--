/*************************
  Author: Defy logic guy
  11:46:32 - 20/07/2025
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
#define NAME "2111D"

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> v(m);
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        v[i] = {x / 100, x};
    }
    sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b)
         { return (a.first == b.first) ? a.second < b.second : a.first < b.first; });

    vector<int> t(n);
    for (int i = 0; i < n; i++)
        t[i] = abs(v[i].first - v[m - i - 1].first);
    vector<int> pf(n + 1, 0);
    for (int i = 0; i < n; i++)
        pf[i + 1] = pf[i] + t[i];
    int mx = -1, k = 0;
    for (int i = 0; i <= n; i++)
    {
        int x = pf[i] + pf[n - i];
        if (x > mx)
        {
            mx = x;
            k = i;
        }
    }

    vector<int> a(n), b(n);
    int cnt = 0;
    for (int i = 0; i < k; i++)
        a[cnt++] = v[i].second;
    for (int i = m - n + k; i < m; i++)
        a[cnt++] = v[i].second;
    cnt = 0;
    for (int i = 0; i < n - k; i++)
        b[cnt++] = v[i].second;
    for (int i = m - k; i < m; i++)
        b[cnt++] = v[i].second;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < 6; j++)
        {
            if (j & 1)
                cout << b[n - i - 1] << ' ';
            else
                cout << a[i] << ' ';
            if (j == 5)
                cout << '\n';
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
    cin >> tt;

    while (tt--)
        solve();
    return 0;
}
