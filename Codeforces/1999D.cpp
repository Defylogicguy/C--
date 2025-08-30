/*************************
  Author: Defy logic guy
  23:22:29 - 16/09/2025
*************************/
#include <bits/stdc++.h>
using namespace std;
// template <typename A, typename B>
// ostream &operator<<(ostream &os, const pair<A, B> &p) { return os << "(" << p.first << ", " << p.second << ")"; }
// template <typename T>
// auto operator<<(ostream &os, const T &c) -> decltype(c.begin(), c.end(), os)
// {
//     for (auto it = c.begin(); it != c.end(); ++it)
//         os << (it == c.begin() ? "{" : ", ") << *it;
//     return os << "}";
// }
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
#define NAME "1999D"

void solve()
{
    string s, t;
    cin >> s >> t;
    int idx = 0;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == '?')
        {
            if (idx < t.size())
                s[i] = t[idx++];
            else
                s[i] = 'a';
        }
        else if (s[i] == t[idx])
            idx++;
    cout << (idx >= t.size() ? "YES\n" : "NO\n");
    if (idx >= t.size())
        cout << s << '\n';
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
