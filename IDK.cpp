/*************************
  Author: Defy logic guy
  10:06:12 - 09/03/2025
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
#define NAME "IDK"

int m, ans;
vector<int> b;

void backtrack(int idx)
{
    if (idx == m)
    {
        ans++;
        return;
    }

    b[idx] = 0;
    backtrack(idx + 1);
    b[idx] = 1;
    backtrack(idx + 1);
}

void solve()
{
    int n, k;
    cin >> n >> m >> k;
    int x;
    for (int i = 0; i < 2 * m; i++)
        cin >> x;

    vector<pair<int, int>> a(k);
    for (int i = 0; i < k; i++)
        cin >> a[i].first >> a[i].second;
    b.assign(m, -1);
    backtrack(0);

    cout << ans << endl;
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
