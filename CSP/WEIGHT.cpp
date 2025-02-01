/*************************
  Author: Defy logic guy
  19:28:15 - 20/01/2025
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
#define NAME "WEIGHT"

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    stack<int> st;
    vector<int> b1(n);
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() and a[st.top()] > a[i])
            st.pop();
        b1[i] = st.empty() ? 0 : st.top() + 1;
        st.push(i);
    }

    vector<int> b2(n);
    st = stack<int>();
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() and a[st.top()] >= a[i])
            st.pop();
        b2[i] = st.empty() ? n + 1 : st.top() + 1;
        st.push(i);
    }

    vector<int> b3(n);
    st = stack<int>();
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() and a[st.top()] < a[i])
            st.pop();
        b3[i] = st.empty() ? 0 : st.top() + 1;
        st.push(i);
    }

    vector<int> b4(n);
    st = stack<int>();
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() and a[st.top()] <= a[i])
            st.pop();
        b4[i] = st.empty() ? n + 1 : st.top() + 1;
        st.push(i);
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
        ans += a[i] * (i + 1 - b3[i]) * (b4[i] - i - 1) - a[i] * (i - b1[i] + 1) * (b2[i] - i - 1);
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
