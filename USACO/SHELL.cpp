/*
 Author: Defy logic guy
 20:37:18 - 31/12/2024
*/
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
#define NAME "shell"

void solve()
{
    int n;
    cin >> n;
    vector<tuple<int, int, int>> a(n);
    for (int i = 0; i < n; i++)
        cin >> get<0>(a[i]) >> get<1>(a[i]) >> get<2>(a[i]);
    int ans = 0;
    for (int st = 1; st <= 3; st++)
    {
        int cur = st;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (get<0>(a[i]) == cur)
                cur = get<1>(a[i]);
            else if (get<1>(a[i]) == cur)
                cur = get<0>(a[i]);
            cnt += (cur == get<2>(a[i]));
        }
        ans = max(ans, cnt);
    }
    cout << ans << endl;
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
