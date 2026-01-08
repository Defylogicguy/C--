/*************************
  Author: Defy logic guy
  14:17:31 - 29/03/2025
*************************/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define maxall(x) *max_element(all(x))
#define minall(x) *min_element(all(x))
#define heap priority_queue
#define pb push_back
#define MOD 1000000007
#define endl '\n'
#define NAME "CONTEST10_DEMCHAN"

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> chan, le;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x % 2 == 0)
            chan.pb(x);
        else
            le.pb(x);
    }

    sort(all(chan));
    sort(all(le));
    int cur = 0;
    while (q--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int x;
            cin >> x;
            x -= cur;
            if (cur & 1)
                cout << upper_bound(all(le), x) - le.begin() << endl;
            else
                cout << upper_bound(all(chan), x) - chan.begin() << endl;
        }
        else
        {
            int x;
            cin >> x;
            cur += x;
        }
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
    // cin >> tt;

    while (tt--)
        solve();
    return 0;
}
