/*************************
  Author: Defy logic guy
  15:13:50 - 01/11/2025
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
#define NAME "LMH_SEAPORT"

void solve()
{
    int m, n;
    cin >> m >> n;
    vector<pair<int, int>> a(n);
    vector<int> s(n), f(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s[i] >> a[i].first;
        a[i].second = i;
    }
    sort(all(a));
    set<pair<int, int>> st;
    int nxt = 0;
    vector<int> v(n, 0);
    int ans = 0;
    for (auto &p : a)
    {
        auto it = st.upper_bound(make_pair(s[p.second], LLONG_MAX));
        if (it != st.begin())
        {
            it--;
            st.erase(it);
            st.insert(make_pair(p.first, it->second));
            v[p.second] = it->second;
            ans++;
        }
        else if (st.size() < m)
        {
            st.insert(make_pair(p.first, ++nxt));
            v[p.second] = nxt;
            ans++;
        }
        else
            v[p.second] = 0;
    }
    cout << ans << '\n';
    for (int i = 0; i < n; i++)
        cout << v[i] << ' ';
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
