/*************************
  Author: Defy logic guy
  23:53:46 - 05/08/2025
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
#define NAME "VNOJ-QBRECT"

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            int x;
            cin >> x;
            if (x)
                a[i][j] = a[i - 1][j] + 1;
        }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        vector<int> l(m + 1), r(m + 1);
        stack<int> st;
        for (int j = 1; j <= m; j++)
        {
            while (st.size() and a[i][st.top()] >= a[i][j])
                st.pop();
            l[j] = st.size() ? st.top() + 1 : 1;
            st.push(j);
        }
        while (st.size())
            st.pop();
        for (int j = m; j >= 1; j--)
        {
            while (st.size() and a[i][st.top()] >= a[i][j])
                st.pop();
            r[j] = st.size() ? st.top() - 1 : m;
            st.push(j);
        }
        for (int j = 1; j <= m; j++)
            ans = max(ans, a[i][j] * (r[j] - l[j] + 1));
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
