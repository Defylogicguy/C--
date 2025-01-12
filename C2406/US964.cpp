/*************************
  Author: Defy logic guy
  20:33:11 - 11/01/2025
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
#define NAME "US964"

void solve()
{
    int n;
    string s;
    cin >> n >> s;
    for (int sz = 1; sz <= n; sz++)
    {
        set<string> st;
        for (int i = 0; i + sz <= n; i++)
            st.insert(s.substr(i, sz));
        if (st.size() == n - sz + 1)
        {
            cout << sz << endl;
            return;
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
