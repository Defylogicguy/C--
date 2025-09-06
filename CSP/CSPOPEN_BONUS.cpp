/*************************
  Author: Defy logic guy
  14:43:14 - 06/09/2025
*************************/
#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) { return os << "(" << p.first << ", " << p.second << ")"; }
template <typename T>
auto operator<<(ostream &os, const T &c) -> decltype(c.begin(), c.end(), os)
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
#define NAME "CSPOPEN_BONUS"

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n * m; cin >> a[i / m][i % m], i++)
        ;
    vector<vector<int>> g(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            g[i][j] = ((i + j) & 1ll);
    vector<vector<int>> s(n, vector<int>(m));
    for (int i = 0; i < n * m; i++)
        s[i / m][i % m] = (a[i / m][i % m] == g[i / m][i % m]);
    auto f = [&](int x) -> int
    {
        vector<vector<int>> b(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (s[i - 1][j - 1] == x)
                    b[i][j] = b[i - 1][j] + 1;
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            vector<int> l(m + 1), r(m + 1);
            stack<int> st;
            for (int j = 1; j <= m; j++)
            {
                while (st.size() and b[i][st.top()] >= b[i][j])
                    st.pop();
                l[j] = st.size() ? st.top() + 1 : 1;
                st.push(j);
            }
            while (st.size())
                st.pop();
            for (int j = m; j >= 1; j--)
            {
                while (st.size() and b[i][st.top()] >= b[i][j])
                    st.pop();
                r[j] = st.size() ? st.top() - 1 : m;
                st.push(j);
            }
            for (int j = 1; j <= m; j++)
                ans = max(ans, b[i][j] * (r[j] - l[j] + 1));
        }
        return ans;
    };
    cout << max(f(0), f(1));
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
