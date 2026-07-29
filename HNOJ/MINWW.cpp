/*************************
  Author: Defy logic guy
  13:49:27 - 28/06/2026
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
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define maxall(x) *max_element(all(x))
#define minall(x) *min_element(all(x))
#define heap priority_queue
#define pb push_back
#define MOD 1000000007
#define NAME "MINWW"

const int MAXC = 256;
void solve()
{
    string s, t;
    cin >> s >> t;
    vector<int> need(MAXC, 0);
    for (char c : t)
        need[c]++;
    int cnt = 0;
    for (int i = 0; i < MAXC; i++)
        if (need[i])
            cnt++;
    int cur = 0, ll = -1, l = 0, ans = LLONG_MAX;
    vector<int> a(MAXC, 0);
    for (int r = 0; r < s.size(); r++)
    {
        a[s[r]]++;
        if (need[s[r]] > 0 and a[s[r]] == need[s[r]])
            cur++;
        while (cur == cnt)
        {
            if (r - l + 1 < ans)
                ll = l, ans = r - l + 1;
            a[s[l]]--;
            if (need[s[l]] > 0 and need[s[l]] > a[s[l]])
                cur--;
            l++;
        }
    }
    if (ll == -1)
    {
        cout << -1;
        return;
    }
    cout << s.substr(ll, ans);
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
