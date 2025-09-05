/*************************
  Author: Defy logic guy
  14:56:11 - 05/09/2025
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
#define NAME "GOJO"

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> lmx(n), rmx(n), lmn(n), rmn(n);

    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (st.size() and a[st.top()] < a[i])
            st.pop();
        lmx[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }

    while (st.size())
        st.pop();
    for (int i = n - 1; i >= 0; i--)
    {
        while (st.size() and a[st.top()] <= a[i])
            st.pop();
        rmx[i] = st.empty() ? n : st.top();
        st.push(i);
    }

    while (st.size())
        st.pop();
    for (int i = 0; i < n; i++)
    {
        while (st.size() and a[st.top()] > a[i])
            st.pop();
        lmn[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }

    while (st.size())
        st.pop();
    for (int i = n - 1; i >= 0; i--)
    {
        while (st.size() and a[st.top()] >= a[i])
            st.pop();
        rmn[i] = st.empty() ? n : st.top();
        st.push(i);
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
        ans += a[i] * ((i - lmx[i]) * (rmx[i] - i) - ((i - lmn[i]) * (rmn[i] - i)));

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
