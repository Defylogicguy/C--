/*************************
  Author: Defy logic guy
  23:54:22 - 05/08/2025
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
#define NAME "VNOJ-KAGAIN"

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    stack<int> st;
    vector<int> l(n), r(n);
    for (int i = 0; i < n; i++)
    {
        while (st.size() and a[st.top()] >= a[i])
            st.pop();
        l[i] = st.size() ? st.top() + 1 : 0;
        st.push(i);
    }
    while (st.size())
        st.pop();
    for (int i = n - 1; i >= 0; i--)
    {
        while (st.size() and a[st.top()] >= a[i])
            st.pop();
        r[i] = st.size() ? st.top() - 1 : n - 1;
        st.push(i);
    }
    int ans = 0, mxl = 0, mxr = 0;
    for (int i = 0; i < n; i++)
        if ((r[i] - l[i] + 1) * a[i] > ans)
        {
            ans = (r[i] - l[i] + 1) * a[i];
            mxr = r[i], mxl = l[i];
        }
    cout << ans << ' ' << mxl + 1 << ' ' << mxr + 1 << '\n';
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
    cin >> tt;

    while (tt--)
        solve();
    return 0;
}
