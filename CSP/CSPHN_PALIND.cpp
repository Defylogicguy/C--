/*************************
  Author: Defy logic guy
  14:59:57 - 04/10/2025
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
#define NAME "CSPHN_PALIND"

vector<int> f(const string &t)
{
    int n = t.size();
    vector<int> a(n, 0);
    for (int i = 1; i < n; i++)
    {
        int j = a[i - 1];
        while (j > 0 && t[i] != t[j])
            j = a[j - 1];
        if (t[i] == t[j])
            j++;
        a[i] = j;
    }
    return a;
}

void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    string tmp = s;
    reverse(all(tmp));

    string t = tmp + ' ' + s;
    vector<int> a = f(t);

    string add = s.substr(0, n - a[t.size() - 1]);
    reverse(all(add));

    cout << s + add << endl;
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
