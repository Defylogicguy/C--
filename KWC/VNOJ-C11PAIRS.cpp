/*************************
  Author: Defy logic guy
  23:56:10 - 05/08/2025
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
#define NAME "VNOJ-C11PAIRS"

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    stack<pair<int, int>> st;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int cnt = 1;
        while (st.size() and st.top().first <= a[i])
        {
            ans += st.top().second;
            if (st.top().first == a[i])
                cnt += st.top().second;
            st.pop();
        }
        ans += (st.size() > 0);
        st.push({a[i], cnt});
    }
    cout << ans;
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
