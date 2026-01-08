/*************************
  Author: Defy logic guy
  22:26:46 - 29/04/2025
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
#define NAME "CSPHN_MEASURE"

struct day
{
    int d, i, t;
};

void solve()
{
    int n, g;
    cin >> n >> g;
    vector<day> a(n);
    set<int> st;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int d, idx, t;
        cin >> d >> idx >> t;
        a[i] = {d, idx, t};
        st.insert(idx);
    }

    sort(all(a));

    vector<int> dis;
    for (auto x : st)
    {
        dis.pb(x);
        mp[x] = g;
    }

    int cnt = 0;
    int mx 
    
    for (auto [d, i, t] : a)
    {
        mp[i] += t;
        int mx = 0;
        for (auto x : mp)
            mx = max(mx, x.second);
        vector<int> ndis;
        for (auto x : mp)
            if (x.second == mx)
                ndis.pb(x.first);
        cnt += dis != ndis;
        dis = ndis;
    }
    cout << cnt;
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
