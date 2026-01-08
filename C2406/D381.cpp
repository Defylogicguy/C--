/*************************
  Author: Defy logic guy
  20:26:35 - 22/02/2025
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
#define NAME "D381"

void solve()
{
    int n, w;
    cin >> n >> w;

    vector<pair<int, int>> a;
    for (int i = 0; i < n; i++)
    {
        int s, t, p;
        cin >> s >> t >> p;
        a.pb({s, p});
        a.pb({t, -p});
    }

    int cur = 0;
    sort(all(a));
    for (auto [x, y] : a)
    {
        cur += y;
        if (cur > w)
        {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
}

/********** Other solution *********
vector<int> dif(200005, 0);
void solve()
{
    int n, w;
    cin >> n >> w;

    for (int i = 0; i < n; i++)
    {
        int s, t, p;
        cin >> s >> t >> p;
        dif[s] += p;
        dif[t] -= p;
    }

    for (int i = 0; i < 200005; i++)
    {
        dif[i + 1] += dif[i];
        if (dif[i] > w)
        {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
}
***********************************/

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
