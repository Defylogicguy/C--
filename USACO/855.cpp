/*************************
  Author: Defy logic guy
  10:13:22 - 19/08/2025
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
#define NAME "mixmilk"

void solve()
{
    vector<pair<int, int>> v(3);
    for (int i = 0; i < 3; i++)
        cin >> v[i].first >> v[i].second;
    int cur = 0;    
    for (int _ = 0; _ < 100; _++)
    {
        int d = min(v[cur].second, v[(cur + 1) % 3].first - v[(cur + 1) % 3].second);
        v[cur].second -= d;
        v[(cur + 1) % 3].second += d;
        cur = (cur + 1) % 3;
    }
    for (auto it : v)
        cout << it.second << '\n';
}

signed main()
{
    if (fopen(NAME ".in", "r"))
    {
        freopen(NAME ".in", "r", stdin);
        freopen(NAME ".out", "w", stdout);
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
