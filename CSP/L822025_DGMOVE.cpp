/*************************
  Author: Defy logic guy
  21:34:06 - 17/12/2025
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
#define NAME "L822025_DGMOVE"

void solve()
{
    string s;
    cin >> s;
    int n = s.size();

    string ans = s;

    char mx = '0';
    int pos = -1;
    for (int i = 0; i < n; i++)
        if (s[i] >= mx)
            mx = s[i], pos = i;
    if (pos != -1)
    {
        string t;
        t.pb(s[pos]);
        for (int i = 0; i < n; i++)
            if (i != pos)
                t.pb(s[i]);
        ans = max(ans, t);
    }

    mx = '0';
    pos = -1;
    char bestRemoveDigit = '9' + 1;

    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] < mx)
            if (s[i] < bestRemoveDigit)
            {
                bestRemoveDigit = s[i];
                pos = i;
            }
        mx = max(mx, s[i]);
    }

    if (pos != -1)
    {
        string t;
        for (int i = 0; i < n; i++)
            if (i != pos)
                t.pb(s[i]);
        t.pb(s[pos]);
        ans = max(ans, t);
    }

    cout << ans << '\n';
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
    cin >> tt;

    while (tt--)
        solve();

    return 0;
}
