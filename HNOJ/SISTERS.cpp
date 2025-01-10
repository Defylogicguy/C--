/*
 Author: Defy logic guy
 09:36:47 - 02/01/2025
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
#define NAME "Skibidi"

void solve()
{
    int n;
    cin >> n;

    vector<int> one, two;
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        sum += x;
        if (x % 3 == 1)
            one.pb(x);
        else if (x % 3 == 2)
            two.pb(x);
    }

    sort(all(one));
    sort(all(two));

    if (sum % 3 == 1)
    {
        int rone = (one.size() > 0) ? one[0] : LLONG_MAX;
        int rtwo = (two.size() > 1) ? two[0] + two[1] : LLONG_MAX;

        if (rone == LLONG_MAX && rtwo == LLONG_MAX)
        {
            cout << 0 << endl;
            return;
        }

        sum -= min(rone, rtwo);
    }
    else if (sum % 3 == 2)
    {
        int rtwo = (two.size() > 0) ? two[0] : LLONG_MAX;
        int rone = (one.size() > 1) ? one[0] + one[1] : LLONG_MAX;

        if (rtwo == LLONG_MAX && rone == LLONG_MAX)
        {
            cout << 0 << endl;
            return;
        }

        sum -= min(rtwo, rone);
    }

    cout << sum / 3 << endl;
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
