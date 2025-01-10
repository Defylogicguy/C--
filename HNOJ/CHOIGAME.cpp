/*************************
  Author: Defy logic guy
  09:37:34 - 04/01/2025
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
#define NAME "CHOIGAME"

void solve()
{
    int n, k;
    cin >> n >> k;
    cout << 1 << ' ';
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    set<int> st;
    st.insert(a[0]);

    for (int i = 1; i < n; i++)
    {
        int x = a[i];
        auto lo = st.lower_bound(x);
        bool flag = false;
        if (lo != st.end())
            flag |= (abs(*lo - x) <= k);
        if (lo != st.begin())
        {
            lo--;
            flag |= (abs(*lo - x) <= k);
        }
        if (flag)
            st.insert(x);
        cout << flag << ' ';
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
