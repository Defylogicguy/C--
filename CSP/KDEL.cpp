/*
 Author: Defy logic guy
 21:32:14 - 29/12/2024
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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    map<int, int> mp;
    multiset<int> st;

    int cnt = 0, j = 0, ans = 0;
    for (int i = 0; i < n; i++)
    {
        while (j < n and cnt <= k + 1)
        {
            auto it = st.find(mp[a[j]]);
            if (it != st.end())
                st.erase(it);
            mp[a[j]]++;
            if (mp[a[j]] == 1)
                cnt++;
            st.insert(mp[a[j]]);
            j++;
        }
        ans = max(ans, *st.rbegin());
        st.erase(st.find(mp[a[i]]));
        mp[a[i]]--;
        if (mp[a[i]] == 0)
            cnt--;
        else
            st.insert(mp[a[i]]);
    }
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
