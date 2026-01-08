/*************************
  Author: Defy logic guy
  18:46:53 - 03/10/2025
*************************/
#include <bits/stdc++.h>
using namespace std;
ostream &operator<<(ostream &os, const string &s)
{
    os.write(s.data(), s.size());
    return os;
}
template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) { return os << "(" << p.first << ", " << p.second << ")"; }
template <typename T>
auto operator<<(ostream &os, const T &c) -> typename enable_if<!is_same<T, string>::value, decltype(c.begin(), c.end(), os)>::type
{
    for (auto it = c.begin(); it != c.end(); ++it)
        os << (it == c.begin() ? "{" : ", ") << *it;
    return os << "}";
}
#define dbg(x) cerr << #x << " = " << (x) << '\n';
#define int long long
#define float double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define maxall(x) *max_element(all(x))
#define minall(x) *min_element(all(x))
#define heap priority_queue
#define pb push_back
#define MOD 1000000007
#define NAME "MMLEN"

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<int> l(n + 1, 0), r(n + 1, 0);
    stack<int> st;
    for (int i = 1; i <= n; i++)
    {
        while (st.size() and a[st.top()] <= a[i])
            st.pop();
        l[i] = (st.empty() ? 0 : st.top());
        st.push(i);
    }
    while (st.size())
        st.pop();
    for (int i = n; i >= 1; i--)
    {
        while (st.size() and a[st.top()] < a[i])
            st.pop();
        r[i] = (st.empty() ? n + 1 : st.top());
        st.push(i);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int A = i - l[i];
        int B = r[i] - i;
        ans += a[i] * (B * A * (A + 1) / 2 + A * B * (B - 1) / 2);
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
