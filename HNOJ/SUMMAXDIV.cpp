/*************************
  Author: Defy logic guy
  23:05:36 - 06/10/2025
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
#define NAME "SUMMAXDIV"

struct node
{
    int x, mn, sum;
    node(int x, int mn, int sum) : x(x), mn(mn), sum(sum) {}
};

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<int> prv(n + 1, LLONG_MAX), dp(n + 1, LLONG_MAX);
    prv[0] = 0;
    for (int i = 1; i <= k; i++)
    {
        dp.assign(n + 1, LLONG_MAX);
        stack<node> st;
        for (int j = 1; j <= n; j++)
        {
            int cur = prv[j - 1];
            while (st.size() and st.top().x <= a[j])
            {
                cur = min(cur, st.top().mn);
                st.pop();
            }
            int mn = cur + a[j];
            if (st.size())
                mn = min(mn, st.top().mn);
            st.push({a[i], cur, mn});
            dp[j] = st.top().sum;
        }
        swap(dp, prv);
    }
    cout << prv[n];
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
