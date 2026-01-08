/*************************
  Author: Defy logic guy
  22:49:24 - 04/01/2026
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
    for (auto it = c.begin(); it != c.end(); it++)
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
#define NAME "MM_HSGHN_L9_22_23"

void solve()
{
    string s;
    cin >> s;
    int cnt = 0, cur = ('a' <= s[0] and s[0] <= '9' ? s[0] - '0' : 0);
    set<int> st;
    for (int i = 1; i < s.size(); i++)
        if ('0' <= s[i] and s[i] <= '9')
            cur = cur * 10 + (s[i] - '0');
        else
        {
            if ('0' <= s[i - 1] and s[i - 1] <= '9')
                st.insert(cur);
            cur = 0;
        }
    if ('0' <= s.back() and s.back() <= '9')
        st.insert(cur);
    cout << st.size();
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

    int tt = 1;
    // cin >> tt;

    while (tt--)
        solve();

    return 0;
}
