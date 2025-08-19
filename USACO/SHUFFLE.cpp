/*************************
  Author: Defy logic guy
  10:59:20 - 19/08/2025
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
#define NAME "shuffle"

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i], a[i]--;
    vector<string> b(n);
    for (int i = 0; i < n; i++)
        cin >> b[i];
    for (int _ = 0; _ < 3; _++)
    {
        vector<string> nw(n);
        for (int i = 0; i < n; i++)
            nw[i] = b[a[i]];
        b = nw;
    }
    for (string i : b)
        cout << i << '\n';
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
